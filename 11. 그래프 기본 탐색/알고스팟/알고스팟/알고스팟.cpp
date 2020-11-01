

#include <iostream>
#include <queue>

const int MAX = 101;

using namespace std;

int N, M;
int result;
pair<int, int> moveDir[4] = { {0,1},{1,0},{0,-1},{-1,0} };

string board[MAX];
bool visited[MAX][MAX] = { false };

int BFS(int startX, int startY) {

	priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> q;
	q.push({ 0,{startY,startX} });
	visited[startY][startX] = true;

	while (!q.empty())
	{
		int curCnt = q.top().first;
		int curY = q.top().second.first;
		int curX = q.top().second.second;
		q.pop();
		if (curY==N-1&&curX==M-1)
		{
			return curCnt;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveDir[i].first;
			int nextX = curX + moveDir[i].second;
			if (0<=nextX&&nextX<M&&0<=nextY&&nextY<N)
			{
				if (board[nextY][nextX] == '0' && !visited[nextY][nextX])
				{
					q.push({ curCnt,{nextY,nextX} });
					visited[nextY][nextX] = true;
				}
				if (board[nextY][nextX] == '1' && !visited[nextY][nextX])
				{
					q.push({ curCnt + 1,{nextY,nextX} });
					visited[nextY][nextX] = true;
				}
			}
		}
	}

}

int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	cout << BFS(0, 0);
}

