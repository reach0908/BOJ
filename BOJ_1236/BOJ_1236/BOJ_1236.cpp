// BOJ_1236.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<char>> v;
int main()
{
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		v[i].resize(M);
	}
	vector<bool> narr(N);
	vector<bool> marr(M);
	narr.assign(N, false);
	marr.assign(M, false);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;  j < M;  j++)
		{
			cin >> v[i][j];
			if (v[i][j]=='X')
			{
				narr[i] = true;
				marr[j] = true;
			}
		}
	}
	int ncnt = 0;
	int mcnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (narr[i]==false)
		{
			ncnt++;
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (marr[i] == false)
		{
			mcnt++;
		}
	}
	cout << max(ncnt, mcnt);
}

