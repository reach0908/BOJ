

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define INF 1000000000
using namespace std;

const int COM_MAX = 10001;

int T;
//컴퓨터개수, 의존성개수, 해킹당한 컴퓨터의 번호
int n, d, c;

vector<pair<int, int>> com[COM_MAX];
int visited[COM_MAX];
int dist[COM_MAX];

void func(int start) {
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < com[cur].size(); i++)
		{
			int next = com[cur][i].first;
			int nCost = com[cur][i].second;
			if (dist[next]>cost+nCost)
			{
				dist[next] = cost + nCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	
}


int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			com[b].push_back(make_pair(a, s));
		}
		for (int i = 1; i <= n; i++)
		{
			fill(dist, dist+COM_MAX, INF);
		}
	}
}

