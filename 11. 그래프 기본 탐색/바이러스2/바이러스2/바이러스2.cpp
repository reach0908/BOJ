// 바이러스2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 101;
int N,K;
vector<int> v[MAX];
bool visited[MAX] = {false};

void DFS(int start,int &count) {
	visited[start] = true;
	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i];
		if (!visited[next])
		{
			count++;
			DFS(next,count);
		}
	}
}

int main()
{
    cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	}
	int count = 0;
	DFS(1,count);
	cout << count;
}

