#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 102;
int t,h, w;
string mp[MAX];
bool visited[MAX][MAX];

pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int result = 0;
void BFS(string key)
{
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        visited[curY][curX] = true;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dir[i].first;
            int nextX = curX + dir[i].second;
            if (0 <= nextX && nextX <= w + 1 && 0 <= nextY && nextY <= h + 1 && !visited[nextY][nextX])
            {
                if (mp[nextY][nextX] == '*')
                {
                    continue;
                }
                if (mp[nextY][nextX] == '.')
                {
                    q.push({nextY, nextX});
                }
                if ('A' <= mp[nextY][nextX] && mp[nextY][nextX] <= 'Z')
                {
                    if (key.find(char(mp[nextY][nextX] + 32)) != string::npos)
                    {
                        mp[nextY][nextX] = '.';
                        q.push({nextY, nextX});
                    }
                }
                if ('a' <= mp[nextY][nextX] && mp[nextY][nextX] <= 'z')
                {
                    if (key.find(mp[nextY][nextX]) == string::npos)
                    {
                        key += mp[nextY][nextX];
                        mp[nextY][nextX] = '.';
                        memset(visited, false, sizeof(visited));
                        while (!q.empty())
                        {
                            q.pop();
                        }
                        q.push({nextY, nextX});
                    }
                }
                if (mp[nextY][nextX] == '$')
                {
                    result++;
                    mp[nextY][nextX] = '.';
                    q.push({nextY, nextX});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> t;
    while (t > 0)
    {
        cin >> h >> w;
        //전체 초기화
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < MAX; i++)
            mp[i].clear();
        //상근이가 갈수있는 곳 초기화
        for (int i = 0; i < w + 2; i++)
            mp[0] += '.';
        for (int i = 1; i <= h; i++)
        {
            string temp;
            cin >> temp;
            mp[i] += '.';
            mp[i] += temp;
            mp[i] += '.';
        }
        for (int i = 0; i < w + 2; i++)
            mp[h + 1] += '.';
        string alphabet;
        cin >> alphabet;
        result=0;
        BFS(alphabet);
        cout << result << endl;
        t--;
    }
    return 0;
}
