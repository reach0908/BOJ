
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BOARD_MAX = 51;

int T, M, N, K;

pair<int, int> moveDir[4] = { {-1,0},{1,0},{0,1},{0,-1} };

void DFS(int board[][BOARD_MAX],bool visited[][BOARD_MAX],int startY,int startX) {
    if (board[startY][startX] == 1&&visited[startY][startX]==false) {
        visited[startY][startX] = true;
        for (int i = 0; i < 4; i++)
        {
            DFS(board,visited,startY + moveDir[i].first, startX + moveDir[i].second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        //밭과 방문한 배추 초기화
        int board[BOARD_MAX][BOARD_MAX] = {0};
        bool visited[BOARD_MAX][BOARD_MAX] = { false };
        //밭에 배추심기
        for (int i = 0; i < K; i++)
        {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            board[temp2+1][temp1+1]=1;
        }
        //탐색
        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++) {
                if (visited[i][j]==false&&board[i][j] == 1)
                {
                    DFS(board,visited,i,j);
                    count++;
                }
            }
        }
        cout << count<<endl;
    }
}

