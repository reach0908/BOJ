#include <iostream>
#include <vector>

using namespace std;
const int MAX = 30;

int N,M,H;
int ladderCnt;
bool flag;
bool ladder[MAX][9+2];

void DFS(int y,int cnt){
    if(flag){
        return;
    }
    if(ladderCnt==cnt){
        bool possible = true;
        for (int i = 1; i <= N; i++)
        {
            int row = i;
            for (int j = 0; j < H; j++)
            {
                if(ladder[j][row]){
                    row++;
                }else if(row>1&&ladder[j][row-1]){
                    row--;
                }
            }
            if(i!=row){
                possible=false;
                break;
            }
        }
        if(possible){
            flag=true;
        }
        return;
    }
    for (int i = y; i < H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if(ladder[i][j-1]){
                continue;
            }
            if(ladder[i][j]){
                continue;
            }
            if(ladder[i][j+1]){
                continue;
            }
            ladder[i][j]=true;
            DFS(i,cnt+1);
            ladder[i][j]=false;
        }
    }
    return;
}


int main(int argc, char const *argv[])
{
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        int y,x;
        cin >> y >> x;
        ladder[y-1][x] = true;
    }
    for (int i = 0; i <=3; i++)
    {
        ladderCnt = i;
        DFS(0,0);
        if(flag){
            cout << ladderCnt << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
