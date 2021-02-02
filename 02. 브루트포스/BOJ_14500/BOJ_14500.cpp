#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 501;

int N,M;
int board[MAX][MAX];
bool visited[MAX][MAX];
pair<int,int> moveDir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

int DFS(int y,int x,int cnt){
    if(cnt==4){
        return board[y][x];
    }
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + moveDir[i].first;
        int nextX = x + moveDir[i].second;
        if(0<=nextY&&0<=nextX&&nextY<N&&nextX<M&&!visited[nextY][nextX]){
            visited[nextY][nextX] = true;
            sum = max(sum,board[y][x]+DFS(nextY,nextX,cnt+1));
            visited[nextY][nextX] = false;
        }
    }
    return sum;
}

int mtShape(int y,int x){
    int sum = 0;
    if(y>=1&&x>=1&&x<M-1){
        sum = max(sum,board[y][x-1]+board[y][x]+board[y-1][x]+board[y][x+1]);
    }
    if(y>=1&&x<M-1&&y<N-1){
        sum = max(sum,board[y-1][x]+board[y][x]+board[y][x+1]+board[y+1][x]);
    }
    if(y>=0&&x<M-1&&y<N-1){
        sum = max(sum,board[y][x-1]+board[y][x]+board[y+1][x]+board[y][x+1]);
    }
    if(y>=1&&x>=1&&y<N-1){
        sum = max(sum,board[y-1][x]+board[y][x]+board[y][x-1]+board[y+1][x]);
    }
    return sum;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
          cin >> board[i][j];
      } 
    }
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = true;
            result = max(DFS(i,j,1),result);
            result = max(mtShape(i,j),result);
            visited[i][j] = false;
        }
    }
    cout << result;
    return 0;
}
