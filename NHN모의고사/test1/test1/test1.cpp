
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 101;
const int INF = 999999999;

int N;
int start, dest;

vector<pair<pair<int, int>, pair<int, int>>> v;

int visited[MAX] = { 0 };

vector<int> graph[MAX];
int visited2[MAX] = { 0 };
vector<int> result;

void BFS(int start,int dest) {

    priority_queue<pair<int, int>,vector<pair<int, int>>,less<pair<int, int>>> q;

    q.push(make_pair(0, start));

    visited[start] = 1;

    while (!q.empty()) {

        int cnt = q.top().first;
        int node = q.top().second;
        q.pop();
        cout << node << " ";
        if (node==dest)
        {
            return;
        }

        for (int i = 0; i < graph[node].size(); i++)
        {
            if (!visited[graph[node][i]])
            {
                q.push({ cnt + 1,graph[node][i] });
                visited[graph[node][i]]=1;
            }
        }
    }
}


void makeGrpah() {
    
    for (int i = 0; i < N-1; i++)
    {
        bool isP = false;
        int curR = v[i].first.second;
        int curX = v[i].second.first;
        int curY = v[i].second.second;
        for (int j = i+1; j < N; j++) {
           
            int nextR = v[j].first.second;
            int nextX = v[j].second.first;
            int nextY = v[j].second.second;

            int temp = sqrt(pow(curX - nextX, 2) + pow(curY - nextY, 2));
            
            if (temp < curR)
            {

                graph[i + 1].push_back(j + 1);

                //graph[j + 1].push_back(i + 1);
                visited2[j + 1] = 1;
            }
        }

    }
    
    for (int i = 1; i <= N; i++)
    {
        if (graph[i].size() == 1)
        {
            graph[graph[i][0]].push_back(i);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (graph[i].size() == 1)
        {
            for (int j = 1; j <= N; j++)
            {
                if (graph[j].size() > 2)
                {
                    for (int k = 0; k < graph[j].size(); k++)
                    {
                        if (graph[j][k] == i)
                        {
                            graph[j][k] = -1;
                        }
                    }
                }

            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (visited2[i] == 0)
        {
            graph[i].push_back(0);
            graph[0].push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num,x, y, r;
        cin >>num>> x >> y >> r;
        v.push_back({ {num,r},{x,y} });
    }

    cin >> start >> dest;

    makeGrpah();
    BFS(start,dest);
    return 0;
}

