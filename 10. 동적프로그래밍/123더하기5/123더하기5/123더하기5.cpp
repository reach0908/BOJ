

#include <iostream>

using namespace std;

//최대값
const int MAX = 100000;
//MOD
const long long MOD = 1000000009LL;
//상태에 따른 캐시 뒤에가 1,2,3에 따라 개수
long long cache[MAX][4] = { 0 };

int T,N;

int solve(int num) {
	if ((cache[num][1]+ cache[num][2]+ cache[num][3]) !=0)
	{
		return (cache[num][1] + cache[num][2] + cache[num][3]) % MOD;
	}
	for (int i = 4; i <=num; i++)
	{
		if ((cache[num][1] + cache[num][2] + cache[num][3])!=0)
		{
			continue;
		}
		for (int j = 1; j <=3; j++)
		{
			long long sum = 0;
			for (int k = 1; k <=3; k++)
			{
				if (k == j) {
					continue;
				}
				sum = (sum + cache[i - j][k]) % MOD;
			}
			cache[i][j] = sum;
		}
	}
	return (cache[num][1] + cache[num][2] + cache[num][3]) % MOD;
}

int main()
{
    cin >> T;
	cache[1][1] = cache[2][2] = cache[3][1] = cache[3][2] = cache[3][3] = 1;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << solve(N) << endl;
	}
	return 0;
}

