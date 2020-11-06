

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 101;

int board[MAX][MAX] = {0};

int T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;

	for (int i = 0; i < T; i++)
	{
		
		int temp;
		for (int i = 0; i < MAX; i++)
		{
			memset(board[i], 0, MAX);
		}

		cin >> temp;
		
		for (int j = 0; j < temp; j++)
		{
			int x, y;
			cin >> x >> y;
			if (0<x&&x<=90&&0<y&&y<=90)
			{
				for (int k = y + 1; k <= y + 10; k++)
				{
					for (int l = x + 1; l <= x + 10; l++)
					{
						board[k][l] = 1;
					}
				}
			}
		}
		int result = 0;
		for (int j = 1; j < MAX; j++)
		{
			for (int k = 1; k < MAX; k++)
			{
				if (board[j][k]==1)
				{
					result++;
				}
			}
		}
		cout << result << "\n";
	}
	return 0;
}

