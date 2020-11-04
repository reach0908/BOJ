
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1001;

int board[MAX][MAX];
int cnt[MAX][MAX][2];


pair<int, int> moveDir[4] = { {1,0},{0,1},{0,-1},{-1,0} };

int N, M;

int BFS(int startX, int startY) {

	queue<pair<int,pair<int,int>>> q;
	q.push({ 1,{startY,startX} });
	cnt[startY][startX][1] = 1;
	while (!q.empty()) {
		int curY = q.front().second.first;
		int curX = q.front().second.second;
		int state = q.front().first;
		q.pop();
		if (curY==N-1&&curX==M-1)
		{
			return cnt[curY][curX][state];
		}
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveDir[i].first;
			int nextX = curX + moveDir[i].second;
			if (0<=nextX&&nextX<M&&0<=nextY&&nextY<N)
			{
				if (board[nextY][nextX]==1&&state&& cnt[nextY][nextX][state] == 0)
				{
					cnt[nextY][nextX][state-1] = cnt[curY][curX][state] + 1;
					q.push({ state-1,{nextY,nextX} });		
				}
				else if (board[nextY][nextX]==0&&cnt[nextY][nextX][state]==0)
				{
					cnt[nextY][nextX][state] = cnt[curY][curX][state] + 1;
					q.push({ state,{nextY,nextX} });
				}
			}
		}
	}

	return -1;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
			board[i][j] = temp[j] - '0';
	}
	cout << BFS(0, 0);
	return 0;
}