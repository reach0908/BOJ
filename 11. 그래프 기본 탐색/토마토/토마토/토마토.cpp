
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1001;

int board[MAX][MAX] = { 0 };

vector<pair<int, int>> v;
pair<int, int> moveDir[4] = { {1,0}, {0,1},{-1,0},{0,-1} };
int check[MAX][MAX] = { 0 };
int N, M;
int day=0;
void BFS() {
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++)
	{
		q.push({ v[i].first,v[i].second });
		check[v[i].first][v[i].second] = 0;
	}
	while (!q.empty())
	{
		bool isok = false;
		for (int i = 0; i < q.size(); i++)
		{
			int curY = q.front().first;
			int curX = q.front().second;
			
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextY = curY + moveDir[i].first;
				int nextX = curX + moveDir[i].second;
				
				if (0<=nextX&&nextX<M&&0<=nextY&&nextY<N)
				{
					if (board[nextY][nextX]==0)
					{
						check[nextY][nextX] = check[curY][curX] + 1;
						q.push({ nextY,nextX });
						board[nextY][nextX] = 1;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> M >> N;
	int x=0, y=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j]==1)
			{
				v.push_back({ i,j });
			}
		}
	}
	BFS();
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			result = max(result, check[i][j]);
			if (board[i][j]==0)
			{
				cout << -1;
				return 0;
			}
			
		}
	}
	cout << result;
}

