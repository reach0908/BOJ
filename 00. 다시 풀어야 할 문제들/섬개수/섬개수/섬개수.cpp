
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_SIZE = 51;

int arr[MAX_SIZE][MAX_SIZE] = { 0 };
int moveDirX[3] = { -1,0,1 };
int moveDirY[3] = { -1,0,1 };

int visited[51][51] = { 0 };

int result = 0;

void BFS(int h, int w) {
	queue<pair<int,int>> q;
	q.push({h,w});

	visited[h][w] = 1;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;

		q.pop();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				int nextY = curY + moveDirY[i];
				int nextX = curX + moveDirX[j];
				if (visited[nextY][nextX] == 0 && arr[nextY][nextX] == 1) {
					q.push({ nextY,nextX });
					visited[nextY][nextX] = 1;
				}
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int w, h;
	while (1)
	{
		cin >> w >> h;
		if (w==0&&h==0)
		{
			break;
		}
		result = 0;
		for (int i = 0; i < MAX_SIZE; i++)
		{
			memset(visited[i], 0, sizeof(visited[i]));
			memset(arr[i], 0, sizeof(arr[i]));
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int temp;
				cin >> temp;
				arr[i][j] = temp;
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j]==0&&arr[i][j]==1)
				{
					BFS(i, j);
					result++;
				}
			}
		}
		cout << result<<"\n";
	}
	return 0;
}

