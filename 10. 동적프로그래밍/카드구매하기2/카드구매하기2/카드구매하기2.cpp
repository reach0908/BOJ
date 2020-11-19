

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;

int cache[MAX] = { 0 };

int N;

int price[MAX] = { 0 };

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> price[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cache[i] = cache[i - 1] + price[1];
		for (int j = 2; j <= N; j++)
		{
			if (i - j >= 0)
			{
				cache[i] = min(cache[i], cache[i - j] + price[j]);
			}
		}
	}

	cout << cache[N];
	return 0;
}

