
#include <iostream>

using namespace std;

const int MOD = 10007;
const int MAX = 1001;


int N;

long long cache[MAX][10] = { 0 };

int solve() {
    for (int i = 2; i <=N; i++)
    {
        for (int j = 0; j <=9;j++)
        {
            for (int k = 0; k <= j; k++)
            {
                cache[i][j] = (cache[i][j] + cache[i - 1][j - k]) % MOD;
            }
        }
    }
    


    long long result = 0LL;

    for (int i = 0; i < 10; i++)
    {
        result += cache[N][i];
    }
    return result%MOD;
}

int main()
{
    cin >> N;
    for (int i = 0; i < 10; i++)
    {
        cache[1][i] = 1;
    }
    cout << solve();

}
