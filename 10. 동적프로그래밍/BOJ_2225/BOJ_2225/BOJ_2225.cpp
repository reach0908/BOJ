

#include <iostream>

using namespace std;

const int MOD = 1000000000;
const int MAX = 200 + 1;

int N,K;

long long cache[MAX][MAX] = {0};

void solve() {
    for (int i = 0; i <= N; i++)
    {
        cache[1][i] = 1;
    }
    for (int i = 0; i <= K; i++)
    {
        cache[i][0] = 1;
    }

    for (int i = 2; i <=K; i++)
    {
        for (int j = 1; j <= N; j++) {
            cache[i][j] = (cache[i][j - 1] + cache[i - 1][j]) % MOD;
        }
    }
    cout << cache[K][N];
}

int main()
{
    cin >> N >> K;
    solve();
    return 0;
}

