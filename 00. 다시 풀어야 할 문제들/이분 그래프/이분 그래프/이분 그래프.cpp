// 이분 그래프.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 20001;

int K, V, E;

vector<int> graph[MAX];
int nodeColor[MAX];
//DFS는 방문여부확인이 필요없다.
void DFS(int nodeNum, int color)
{
	nodeColor[nodeNum] = color;
	for (int i = 0; i < graph[nodeNum].size(); i++)
	{
		int next = graph[nodeNum][i];
		if (!nodeColor[next])
			DFS(next, 3 - color);
	}
}

bool isBipartiteGraph(void)
{
    //연결된 그래프가 같은 색깔이라면 false;
    for (int i = 1; i <= V; i++){
        for (int j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j];
            if (nodeColor[i] == nodeColor[next])
                return false;
        }
    }
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
    for (int i = 0; i < K; i++)
    {
        for (int j = 1; j < MAX; j++)
             graph[j].clear();
        memset(nodeColor, 0, sizeof(nodeColor));
        cin >> V >> E;

        for (int j = 0; j < E; j++)
        {
            int node1, node2;
            cin >> node1 >> node2;

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        for (int j = 1; j <= V; j++)
            if (nodeColor[j] == 0)
                DFS(j, 1); //1번 색깔부터 시작
        if (isBipartiteGraph())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
