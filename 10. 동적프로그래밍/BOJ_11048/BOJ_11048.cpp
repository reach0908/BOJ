#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 1001;
int N,M;

int board[MAX][MAX];
int cache[MAX][MAX]={0};

void solve()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            int temp = max(max(cache[i-1][j],cache[i][j-1]),cache[i-1][j-1]);
            cache[i][j] = temp + board[i][j];
        }
    }
    cout << cache[N][M];
}
int main(int argc, char const *argv[])
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
        }   
    }
    solve();
    return 0;
}
