
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MAX = 500000*2 + 1;
const int INF = 987654321;

int N;
int M;
int channel[MAX];
bool broken[10] = { false };

int check(int n) {
	if (n==0)
	{
		return broken[0] ? false : true;
	}
	int len = 0;
	while (n>0)
	{
		if (broken[n % 10]) {
			return 0;
		}
		len += 1;
		n /= 10;
	}
	return len;
}

void solve() {
	int ans = abs(N - 100);
	for (int i = 0; i < MAX; i++)
	{
		int c = i;
		ans = min(ans, (check(c) ? check(c) + abs(N - c) : abs(N - 100)));
	}
	cout << ans;
}

int main()
{
    cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		broken[temp] = true;
	}
	solve();
	
}
