// 미로탐색.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 101;

int N, M;
string board[MAX];
int check[MAX][MAX] = { 0 };
pair<int, int> moveDir[4] = { {1,0}, {0,1},{0,-1},{-1,0}};

void BFS(int startX,int startY) {
	queue<pair<int, int>> q;
	q.push({ startY,startX });
	check[startY][startX] = 1;
	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + moveDir[i].second;
			int nextY = curY + moveDir[i].first;
			if (0<=nextX&&nextX<M&&0<=nextY&&nextY<N)
			{
				if (board[nextY][nextX]=='1'&&check[nextY][nextX]==0)
				{
					q.push({ nextY,nextX });
					check[nextY][nextX] = check[curY][curX] + 1;
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
    cin >> N>>M;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}
	BFS(0,0);
	cout << check[N - 1][M - 1];
	return 0;
}

