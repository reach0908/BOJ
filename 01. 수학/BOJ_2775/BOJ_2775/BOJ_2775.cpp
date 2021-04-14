
#include <iostream>

using namespace std;

const int MAX = 15;

int K, N,T;
int res;

int arr[MAX][MAX];

void solve() {
	for (int i = 1; i < MAX; i++)
	{
		arr[0][i] = i;
	}
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			int cnt = 0;
			
				for (int x = 1; x <=j; x++)
				{
					cnt += arr[i-1][x];
				}
			
			arr[i][j] = cnt;
		}
	}
}

int main()
{
	cin >> T;
	solve();
	while (T--)
	{
		cin >> K >> N;
		cout << arr[K][N] << endl;
	}
}

