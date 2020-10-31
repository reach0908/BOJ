
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100001;

int N, K;
int visited[MAX] = {0};

int BFS(int start, int dest) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0 ,start });
	visited[start] = 1;
	while (!q.empty())
	{
		int curLoc = q.top().second;
		int curSec = q.top().first;
		q.pop();
		if (curLoc == dest) {
			return curSec;
		}
		if (0 <= curLoc - 1 && visited[curLoc - 1] == 0)
		{
			visited[curLoc - 1] = 1;
			q.push({ curSec + 1,curLoc - 1 });
		}
		if (curLoc + 1 < MAX && visited[curLoc + 1] == 0)
		{
			visited[curLoc + 1] = 1;
			q.push({ curSec + 1 ,curLoc + 1 });
		}
		if (curLoc * 2 < MAX && visited[curLoc * 2] == 0)
		{
			visited[curLoc * 2] = 1;
			q.push({ curSec ,curLoc * 2 });
		}
	}
}

int main()
{
    cin >> N >> K;
    cout << BFS(N, K);
}

