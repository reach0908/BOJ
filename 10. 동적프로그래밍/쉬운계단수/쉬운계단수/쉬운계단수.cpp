

#include <iostream>

using namespace std;

const int MAX = 101;
const long long MOD = 1000000000LL;

long long cache[MAX][10] = { 0 };
int cache2[MAX] = { 0 };
int N;

int solve(int num) {
    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            if (j == 0)
            {
                cache[i][j] = cache[i - 1][j + 1];
            }
            else if (j == 9)
            {
                cache[i][j] = cache[i - 1][j - 1];
            }
            else
            {
                cache[i][j] = (cache[i - 1][j + 1] + cache[i - 1][j - 1]) % MOD;
            }
        }
    }
    long long result =0LL;
    for (int i = 0; i <= 9; i++)
    {
        result += cache[num][i];
    }
    return result % MOD;
}


int main()
{
    cin >> N;
    for (int i = 1; i <=9; i++)
    {
        cache[1][i] = 1;
    }
    cout << solve(N);

    return 0;
}

