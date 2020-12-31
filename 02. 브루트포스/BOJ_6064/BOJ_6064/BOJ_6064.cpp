

#include <iostream>

using namespace std;

const int MAX = 40000;

int M, N, x, y;
int T;

int gcd(int a, int b) {
	while (b!=0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void solve() {
	int curM = 1;
	int curN = 1;
	int cnt = x%(M+1);
	int tempY = x;
	for (int i = 0; i < N; i++)
	{
		int ty = tempY % N == 0 ? N : tempY % N;
		if (ty==y)
		{
			break;
		}
		tempY = ty + M;
		cnt += M;
	}
	if (cnt>M*N/gcd(M,N))
	{
		cout << -1 << endl;
		return;
	}
	cout << cnt << endl;
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;
		solve();
	}
}

