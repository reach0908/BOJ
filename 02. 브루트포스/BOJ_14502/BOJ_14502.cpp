#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 8;

int board[MAX][MAX];
int temp[MAX][MAX];
int virusSpread[MAX][MAX];
int N,M;

vector<pair<int,int>> virus;
int result = 0;
pair<int,int> moveDir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

void check(){
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(virusSpread[i][j]==0){
                cnt++;
            }
        }
    }
    result = max(result,cnt);
}

void spread(){
    queue<pair<int,int>> q;
    memcpy(virusSpread,temp,sizeof(temp));
    for (int i = 0; i < virus.size(); i++)
    {
        q.push(virus[i]);
    }
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + moveDir[i].first;
            int nextX = curX + moveDir[i].second;
            if(0<=nextY&&0<=nextX&&nextY<N&&nextX<M){
                    if(virusSpread[nextY][nextX]==0){
                        virusSpread[nextY][nextX] = 2;
                        q.push({nextY,nextX});     
                    }
            }
        }
    }
    check();
}

void wall(int cnt){
    if(cnt==3){
        spread();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(temp[i][j]==0){
                temp[i][j]=1;
                wall(cnt+1);
                temp[i][j]=0;
            }
        }
        
    }
    
}

void solve(){
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(board[i][j]==0){
                memcpy(temp,board,sizeof(board));
                temp[i][j]=1;
                wall(1);
                temp[i][j]=0;
            }
        }
    }
    cout << result;
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if(board[i][j]==2){
                virus.push_back({i,j});
            }
        }
    }
    solve();
    return 0;
}
