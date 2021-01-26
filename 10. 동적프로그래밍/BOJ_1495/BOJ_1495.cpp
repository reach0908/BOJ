#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX = 1001;

int N, S, M;

int v[101];
int dp[101][MAX] = {
    0
};
int main(int argc, char const *argv[])
{
    cin >> N >> S >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }
    dp[0][S] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (dp[i - 1][j] == 0)
            {
                continue;
            }
            if (j-v[i]>=0)
            {
                dp[i][j - v[i]] = 1;
            }
            if (j + v[i] <= M)
            {
                dp[i][j + v[i]] = 1;
            }
        }
    }
    int res = -1;
    for (int i = 0; i <= M; i++)
    {
        if (dp[N][i] == 1)
        {
            res = max(res, i);
        }
    }
    cout << res;
    return 0;
}
