

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 20;

bool visited[27] = {false};
int board[MAX][MAX] = {0};
int R, C;

pair<int, int> moveDir[4] = { {-1,0},{1,0},{0,1},{0,-1} };
int result = 0;


void solve(int cnt, int startX, int startY) {
	
	result = max(cnt, result);
	for (int i = 0; i < 4; i++)
	{
		int nextX = startX + moveDir[i].second;
		int nextY = startY + moveDir[i].first;
		if (nextX>=0&&nextX < C && nextY < R&&nextY>=0) {
			if (board[nextY][nextX] && !visited[board[nextY][nextX]]) {
				visited[board[nextY][nextX]] = true;
				solve(cnt + 1, nextX, nextY);
				visited[board[nextY][nextX]] = false;
			}
		}
	}
	
}

int main()
{
    cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < C; j++)
		{
			board[i][j] = (temp[j] - 'A')+1;
		}
	}
	visited[board[0][0]] = true;
	solve(1, 0, 0);
	
	cout << result;
}

