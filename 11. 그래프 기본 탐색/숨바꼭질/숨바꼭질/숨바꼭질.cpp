// 숨바꼭질.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
int visited[MAX] = { 0 };
int N, K;
int result;

void BFS(int start, int dest) {
    queue<pair<int, int>> q;
    q.push({ start,0 });
    visited[start] = 1;
    while (!q.empty())
    {
        int curloc = q.front().first;
        int cursec = q.front().second;
        q.pop();
        if (curloc==dest)
        {
            result = cursec;
            return;
        }
        if (curloc+1<MAX&&!visited[curloc+1])
        {
            visited[curloc] = 1;
            q.push(make_pair(curloc + 1, cursec + 1));
        }
        if (curloc - 1 >=0 && !visited[curloc-1])
        {
            visited[curloc] = 1;
            q.push(make_pair(curloc - 1, cursec + 1));
        }
        if (curloc*2 < MAX && !visited[curloc*2])
        {
            visited[curloc] = 1;
            q.push(make_pair(curloc*2, cursec + 1));
        }
    }

}

int main()
{
    cin >> N >> K;
    BFS(N, K);
    cout << result;
    return 0;
}
