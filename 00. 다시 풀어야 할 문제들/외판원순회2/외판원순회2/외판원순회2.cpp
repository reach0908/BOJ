// 외판원순회2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000001
using namespace std;
const int MAX = 10;
int N;

int v[MAX][MAX];
vector<int> node;
int main()
{
	cin>> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
		node.push_back(i);
	}
	int MIN = INF;
	do
	{
		bool cango = true;
		int dist = 0;
		for (int i = 0; i < node.size()-1; i++)
		{
			int startNode = node[i];
			int nextNode = node[i + 1];
			int cost = v[startNode][nextNode];
			if (cost==0)
			{
				cango = false;
				break;
			}
			else {
				dist += cost;
			}
		}
		if (cango==true)
		{
			dist += v[node[N - 1]][node[0]];
			MIN = min(MIN, dist);
		}
	} while (next_permutation(node.begin(),node.end()));
	cout << MIN;
	return 0;
}

