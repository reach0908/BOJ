#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
int N,M;

const int MAX = 50;

int board[MAX][MAX] = {0};
int startY,startX,startDir;
typedef struct
{
	int y, x;
}Dir;
Dir moveDir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // N E S W

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N >> M;
    cin >> startY >> startX >> startDir;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    int result =0;
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{startY,startX},startDir});
    
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int curDir = q.front().second;
        
        if(board[y][x]==0){
            board[y][x]==2;
            result++;
        }
        q.pop();
        
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            int nextDir = (curDir + (3-i))%4;
            int nextY = y + moveDir[nextDir].y;
            int nextX = x + moveDir[nextDir].x;
            if(0<=nextY&&0<=nextX&&nextY<N&&nextX<M){
                if(!board[y][x]){
                    q.push({{nextY,nextX},nextDir});
                    flag=true;
                    break;
                }
            }
        }
        if(!flag){
            int nextY = y - moveDir[curDir].y;
            int nextX = x - moveDir[curDir].x;
            if((0<=nextY&&0<=nextX&&nextY<N&&nextX<M)&&board[nextY][nextX]!=1){
                q.push({{nextY,nextX},curDir});
            }else{
                break;
            }
        }
    }
    cout << result;
    return 0;
}
