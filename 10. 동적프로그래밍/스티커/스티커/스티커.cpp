

#include <iostream>
#include <algorithm>

using namespace std;

int T, n;

const int MAX = 100001;
int board[MAX][2] = { 0 };
int cache[MAX][2] = { 0 };

int solve(int startX,int startY, int curScore) {
	cache[0][0] = cache[0][1] = 0;
	cache[1][0] = board[1][0];
	cache[1][1] = board[1][1];

	for (int i = 2; i <= n; i++)
	{
		cache[i][0] = max(cache[i - 1][1], (i - 2 > 0) ? cache[i - 2][1] : 0) + board[i][0];
		cache[i][1] = max(cache[i - 1][0], (i - 2 > 0) ? cache[i - 2][0] : 0) + board[i][1];
	}
	return max(cache[n][0], cache[n][1]);

}

int main()
{
    cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				cin >> board[k][j];
			}
		}
		
		cout << solve(0, 0, 0) << endl;
	}
    return 0;
}

