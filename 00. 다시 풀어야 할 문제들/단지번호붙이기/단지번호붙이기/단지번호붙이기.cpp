// 단지번호붙이기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 25;
string s[MAX];
int visited[MAX][MAX] = { 0 };

vector<int> res;

int N,cnt;
pair<int, int> moveDir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
void DFS(int startY,int startX) {
	visited[startY][startX] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int y = startY + moveDir[i].first;
		int x = startX + moveDir[i].second;
		if (0 <= x && x < N && 0 <= y && y < N) {
			if (s[y][x] == '1' && visited[y][x] == 0)
			{
				DFS(y, x);
			}
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (s[i][j]=='1'&&visited[i][j]==0)
			{
				cnt = 0;
				DFS(i, j);
				res.push_back(cnt);
			}
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "\n";
	}
	
}

