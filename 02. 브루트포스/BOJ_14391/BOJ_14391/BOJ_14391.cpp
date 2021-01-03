// BOJ_14391.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MAX = 4;
int result = -1;

int N, M;
string s[MAX];

int board[MAX][MAX] = { 0 };

void solve() {
	
}

int main()
{
	cin >> N >> M;
	for (int i=0;i<N;i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = temp[j] - '0';
		}
	}
	for (int bit = 0; bit < (1 << (N * M)); bit++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int num = 0;
			for (int j = 0; j < M; j++)
			{
				int k = i * M + j;
				if ((bit & (1 << k)) == 0) {
					num = num * 10 + board[i][j];
				}
				else {
					sum += num;
					num = 0;
				}
			}
			sum += num;
		}
		for (int j = 0; j < M; j++)
		{
			int num = 0;
			for (int i = 0; i < N; i++)
			{
				int k = i * M + j;
				if ((bit & (1 << k)) != 0) {
					num = num * 10 + board[i][j];
				}
				else {
					sum += num;
					num = 0;
				}
			}
			sum += num;
		}
		result = max(result, sum);
	}
	
	cout << result << endl;
	return 0;
}
