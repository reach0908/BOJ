// 외판원순회2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999999999
using namespace std;

const int MAX = 11;

int board[MAX][MAX];

int N;

int MIN = INF;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
		
	}
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		v[i] = i;
	}
	do
	{
		bool cango = true;
		int sum = 0;
		for (int i = 0; i < N-1; i++)
		{
			int cost = board[v[i]][v[i + 1]];
			if (cost==0)
			{
				cango = false;
				break;
			}
			else {
				sum += cost;
			}
			
		}
		if (cango&& board[v[N - 1]][v[0]]!=0)
		{
			sum += board[v[N - 1]][v[0]];
			MIN = min(MIN, sum);
		}
	} while (next_permutation(v.begin(),v.end()));
	cout << MIN;

	return 0;
}