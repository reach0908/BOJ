

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 999999999;
const int MAX = 2000;
int S;
int sec = INF;
int visited[MAX][MAX] = {0};
void BFS(int screen,int clip) {
    queue<pair<int, pair<int,int>>> q;
    q.push({ 0,{ screen,clip } });
    visited[screen][clip] = 1;
    while (!q.empty())
    {
        int curscreen = q.front().second.first;
        int curclip = q.front().second.second;
        int cursec = q.front().first;
        q.pop();
        if (curscreen == S)
        {
            sec = cursec;
            return;
        }
        if (curscreen > 0 && curscreen < MAX) {
            if (visited[curscreen][curscreen]==0)
            {
                visited[curscreen][curscreen] = 1;
                q.push({ cursec + 1,{curscreen,curscreen} });
            }
            if (visited[curscreen-1][curclip]==0)
            {
                visited[curscreen - 1][curclip] == 1;
                q.push({ cursec + 1,{curscreen - 1,curclip} });
            }
        }
        if (curclip > 0 && curscreen + curclip < MAX) {
            if (visited[curscreen + curclip][curclip]==0)
            {
                visited[curscreen + curclip][curclip] = 1;
                q.push({ cursec + 1,{curscreen + curclip,curclip} });
            }
        }
    }
}


int main()
{
    cin >> S;
    BFS(1,0);
    cout << sec;
}

