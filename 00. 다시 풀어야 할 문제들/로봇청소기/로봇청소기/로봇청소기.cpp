// 로봇청소기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <algorithm>

const int MAX = 51;

using namespace std;

pair<int, int> moveDir[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int visited[MAX][MAX] = { 0 };
int board[MAX][MAX] = { 0 };
int N,M;

int result=0;

queue < pair<int, pair<int,int>>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	
	q.push({ d,{r,c} });
	while (!q.empty())
	{
		int startY = q.front().second.first;
		int startX = q.front().second.second;
		int pointNum = q.front().first;
		if (visited[startY][startX] == 0)
		{
			visited[startY][startX] = 1;
			result++;
		}
		q.pop();

		bool canClean = false;
		for (int i = 0; i < 4; i++)
		{
			int nextNum = ((3 - i) + pointNum) % 4;
			int nextY = startY + moveDir[nextNum].first;
			int nextX = startX + moveDir[nextNum].second;
			if (0<= nextX&&nextX < M && 0<=nextY&& nextY < N && board[nextY][nextX] == 0 && visited[nextY][nextX] == 0)
			{
				q.push(make_pair(nextNum, make_pair(nextY, nextX)));
				canClean = true;
				break;
			}
		}
		if (canClean == false) {
			int backY = startY - moveDir[pointNum].first;
			int backX = startX - moveDir[pointNum].second;
			if (0 <= backX&&backX < M && 0<= backY&& backY < N && board[backY][backX] == 0)
			{
				q.push(make_pair(pointNum, make_pair(backY, backX)));
			}
			else {
				break;
			}
		}
	}
	cout << result;
	return 0;
}

