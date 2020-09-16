#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int COM_MAX = 10001;

bool visited[COM_MAX] = { false };
vector<int> com[COM_MAX];
int result[COM_MAX];
int N, M;

int BFS(int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    int count = 1;
    while (!q.empty())
    {
        int next = q.front();
        q.pop();
        for (int i = 0; i < com[next].size(); i++)
        {
            if (!visited[com[next][i]])
            {
                q.push(com[next][i]);
                visited[com[next][i]] = true;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        com[temp2].push_back(temp1);
    }
    
    for (int i = 1; i <=N; i++)
    {
        memset(visited, false, COM_MAX);
        result[i]=BFS(i);
    }
    int maxCnt = 0;
    for (int i = 1; i <=N; i++)
    {
        maxCnt = max(maxCnt, result[i]);
    }
    for (int i = 1; i <=N; i++)
    {
        if (maxCnt == result[i])
        {
            cout << i << " ";
        }
    }
}

