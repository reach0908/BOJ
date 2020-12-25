

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int N;

int A[MAX] = { 0 };
int cache[MAX] = { 0 };

int solve() {
	for (int i = 1; i <=N; i++)
	{
		cache[i] = 1;
		for (int j = 1; j <=i; j++)
		{
			if (A[i]>A[j]&&cache[i]<cache[j]+1)
			{
				cache[i] = cache[j] + 1;
			}
		}
	}
	int maxN = 0;
	for (int i = 1; i <= N; i++)
	{
		maxN = max(maxN, cache[i]);
	}

	return maxN;

}

int main()
{
    cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	cout << solve();
}

