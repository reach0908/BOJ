
#include <iostream>
#include <cmath>

using namespace std;
const int MAX = 100001;

int N;
int cache[MAX] = { 0 };
void solve() {
	for (int i = 1; i <=N; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			if (cache[i]>cache[i-j*j]+1||cache[i]==0)
			{
				cache[i] = cache[i - j * j] + 1;
			}
		}
	}
	cout << cache[N];
}

int main()
{
    cin >> N;
	cache[0] = 0;
    solve();
}

