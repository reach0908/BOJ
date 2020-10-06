

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1001;

int N, M;
vector<int> v[MAX];
int visited[MAX] = { 0 };

int cnt = 0;

void BFS(int n){
	if (visited[n]==1)
	{
		return;
	}
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (visited[next] == 0) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}
	cnt++;
}

int main()
{
    cin >> N >> M;
	for (int i= 0;i < M;i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		BFS(i);
	}
	cout << cnt;
	return 0;
}

