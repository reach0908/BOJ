#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 100000+1;
const int INF = 1e9;
bool visited[MAX] = {false};
int result[MAX]={0};
int minCnt = INF;

int N,K;

void BFS()
{
    queue<pair<int, int>> q;
    q.push({0, N});
    visited[N] = true;
    while (!q.empty())
    {
        int curCnt = q.front().first;
        int curLoca = q.front().second;
        q.pop();
        if (curLoca == K)
        {
            minCnt = min(minCnt, curCnt);
            result[curCnt]++;
            continue;
        }
        visited[curLoca] = true;
        if (curLoca - 1 >= 0 && !visited[curLoca - 1])
        {
            q.push({curCnt + 1, curLoca - 1});
        }
        if (curLoca + 1 < MAX && !visited[curLoca + 1])
        {
            q.push({curCnt + 1, curLoca + 1});
        }
        if (curLoca * 2 < MAX && !visited[curLoca * 2])
        {
            q.push({curCnt + 1, curLoca * 2});
        }
    }
}
int main()
{
    cin >> N >> K;
    BFS();
    cout << minCnt << endl;
    cout << result[minCnt]<< endl;
    return 0;
}
