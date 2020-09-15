
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 101;
int N,K;
vector<int> v[MAX];
bool visited[MAX] = { false };



void BFS(int start) {
	int count = 0;
	int result;
	queue<pair<int, int>> q;
	q.push(make_pair(start,count++));
	visited[start] = true;
	while (!q.empty())
	{
		int next = q.front().first;
		result = q.front().second;
		q.pop();
		for (int i = 0; i < v[next].size(); i++)
		{
			if (!visited[v[next][i]])
			{
				q.push(make_pair(v[next][i],count++));
				visited[v[next][i]] = true;
			}

		}
	}
	cout << result;
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= K; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	}
	BFS(1);
}

