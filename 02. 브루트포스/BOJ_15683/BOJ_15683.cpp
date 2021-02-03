#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 8;
const int INF = 1e9;

int N,M;
typedef struct cctv{

    int y,x;
}cctv;

cctv moveDir[4] = {{-1,0},{0,1},{1,0},{0,-1}};

int board[MAX][MAX];
int temp[MAX][MAX];
bool visited[MAX][MAX][4];

vector<cctv> cctvArr;
vector<int> angle;
int result = 0;
//모듈러 연산, BFS, DFS

int checkSharp(){
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(temp[i][j]==0){
                cnt++;
            }
        }
    }
    return cnt;
}

void DFS(int cnt){
    if (cnt == cctvArr.size())
    {
        for (size_t i = 0; i < angle.size(); i++)
        {
            int y = cctvArr[i].y;
            int x = cctvArr[i].x;
            for (int j = 0; j < 4; j++)
            {
                if(visited[y][x][j]){
                    int nextY = y + moveDir[(angle[i]+j)%4].y;
                    int nextX = x + moveDir[(angle[i]+j)%4].x;
                    while (1)
                    {
                        if(temp[nextY][nextX]==6){
                            break;
                        }
                        if(!(0<=nextY&&0<=nextX&&nextX<M&&nextY<N)){
                            break;
                        }
                        if(temp[nextY][nextX]==0){
                            temp[nextY][nextX] = -1;
                        }
                        nextY += moveDir[(angle[i]+j)%4].y;
                        nextX += moveDir[(angle[i]+j)%4].x;
                    }
                    
                }
            }
        }
        result = min(result,checkSharp());
        memcpy(temp,board,sizeof(board));
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        angle.push_back(i);
        DFS(cnt+1);
        angle.pop_back();
    }
    
}

void solve(){
    //어떤씨시티비라도 한번이라도 회전하면 BFS 돌리기
    result = INF;
    memcpy(temp,board,sizeof(board));
    DFS(0);
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
            if (1 <= board[i][j] && board[i][j] <= 5)
            {
                cctvArr.push_back({i, j});
            }
            switch (board[i][j])

            {

            case 1:

                visited[i][j][0] = true;

                break;

            case 2:

                visited[i][j][0] = true;

                visited[i][j][2] = true;

                break;

            case 3:

                visited[i][j][0] = true;

                visited[i][j][1] = true;

                break;

            case 4:

                visited[i][j][0] = true;

                visited[i][j][1] = true;

                visited[i][j][2] = true;

                break;

            case 5:

                visited[i][j][0] = true;

                visited[i][j][1] = true;

                visited[i][j][2] = true;

                visited[i][j][3] = true;

                break;
            }
        }
    }
    solve();
    return 0;
}
