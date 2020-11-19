

#include <iostream>

using namespace std;

const int MAX = 1000001;
const int MOD = 1000000009;
long long cache[MAX] = { 0 };

int N, T;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cache[1] = 1;
		cache[2] = 2;
		cache[3] = 4;
		for (int j = 4; j <= N; j++)
		{
			cache[j] = (cache[j - 1] + cache[j - 2] + cache[j - 3])%MOD;
		}
		cout << cache[N]%MOD << endl;
	}
	return 0;
}

