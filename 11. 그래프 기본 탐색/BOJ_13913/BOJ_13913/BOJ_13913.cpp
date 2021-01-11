
#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MAX = 100000 + 1;

int N, K;
bool visited[MAX];
int parent[MAX];

vector<int> v;

void BFS() {
	queue<pair<int, int>> q;
	q.push({ 0,N });
	visited[N] = true;
	while (!q.empty())
	{
		
		for (int i = 0; i < q.size(); i++)
		{
			int curCnt = q.front().first;
			int curLoca = q.front().second;
			q.pop();
			if (curLoca == K) {
				cout << curCnt << endl;
				int idx = curLoca;
				while (idx!=N)
				{
					v.push_back(idx);
					idx= parent[idx];
				}
				v.push_back(N);
				return;
			}
			else {
				if (curLoca - 1 >= 0 && !visited[curLoca - 1])
				{
					visited[curLoca - 1] = true;
					q.push({ curCnt + 1,curLoca - 1 });
					parent[curLoca-1] = curLoca;
				}
				if (curLoca + 1 < MAX && !visited[curLoca + 1]) {
					visited[curLoca + 1] = true;
					q.push({ curCnt + 1,curLoca + 1 });
					parent[curLoca+1] = curLoca;
					
				}
				if (curLoca * 2 < MAX && !visited[curLoca * 2]) {
					visited[curLoca * 2] = true;
					q.push({ curCnt + 1,curLoca * 2});
					parent[curLoca*2] = curLoca;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	BFS();
	for (int i = v.size()-1; i >=0; i--)
	{
		cout << v[i] << " ";
	}
	return 0;
}
