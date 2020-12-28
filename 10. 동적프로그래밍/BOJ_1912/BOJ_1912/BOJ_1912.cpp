

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int A[MAX];
int cache[MAX];

int N;

void solve() {
	cache[0] = A[0];
	for (int i = 1; i < N; i++)
	{
		cache[i] = A[i];
		if (cache[i-1]>0&&cache[i]+cache[i-1]>A[i])
		{
			cache[i] += cache[i - 1];
		}
	}
	int res = -MAX;
	for (int i = 0; i < N; i++)
	{
		res = max(res, cache[i]);
	}
	cout << res;
}

int main()
{
    cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	solve();

	return 0;
}

