#include <iostream>

using namespace std;
const int MAX = 100;
int N;
int board[MAX][MAX];
long long cache[MAX][MAX]={0};

void solve()
{

    cache[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == N - 1 && j == N - 1)
            {
                break;
            }
            if (cache[i][j] != 0)
            {
                int d = board[i][j];
                if (i + d < N)
                {
                    cache[i + d][j] += cache[i][j];
                }
                if (j + d < N)
                {
                    cache[i][j + d] += cache[i][j];
                }
            }
        }
    }
    cout << cache[N - 1][N - 1];
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }

    }
    solve();
    return 0;
}
