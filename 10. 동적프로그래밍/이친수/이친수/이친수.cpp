#include <iostream>

using namespace std;

const int MAX = 91;

int N;

long long cache[MAX][2] = { 0 };

int main()
{
    cache[1][0] = 0;
    cache[1][1] = 1;
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
        cache[i][1] = cache[i - 1][0];
    }
    cout << cache[N][0] + cache[N][1];
    return 0;
}