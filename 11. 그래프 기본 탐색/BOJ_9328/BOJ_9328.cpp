#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 102;

int h,w;

char mp[MAX][MAX];
bool visited[MAX][MAX];

typedef struct options
{
    int y;
    int x;
}options;

pair<int,int> dir[4]={{-1,0},{1,0},{0,-1},{0,1}};

int BFS(string key)
{
    int result=0;
    queue<options> q;
    options op = {0, 0};
    visited[0][0] = true;
    q.push(op);
    while (!q.empty())
    {
        int curX = q.front().x;
        int curY = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dir[i].first;
            int nextX = curX + dir[i].second;
            if (0 <= nextX && nextX <= w + 1 && 0 <= nextY && nextY <= h + 1)
            {
                if (!visited[nextY][nextX]&&mp[nextY][nextX]!='*')
                {
                    if (mp[nextY][nextX] == '.')
                    {
                        q.push({nextY, nextX});
                        visited[nextY][nextX] = true;
                    }
                    if ('A' <= mp[nextY][nextX]&& mp[nextY][nextX] <= 'Z')
                    {
                        if (key.find(mp[nextY][nextX]+32))
                        {
                            q.push({nextY, nextX});
                            visited[nextY][nextX] = true;
                        }
                    }
                    if ('a' <= mp[nextY][nextX]&&mp[nextY][nextX] <= 'z')
                    {
                        string nextKey = key + mp[nextY][nextX];
                        q.push({nextY, nextX});
                        visited[nextY][nextX] = true;
                    }
                    if (mp[nextX][nextY]=='$')
                    {
                        q.push({nextY,nextX});
                        visited[nextY][nextX]=true;
                        result++;
                    }
                }
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t>0)
    {
        cin >> h >> w;
        string temp;
        //전체 초기화
        for (int i = 0; i <= MAX; i++)
        {
            memset(mp[i], '*', sizeof(mp[i]));
            memset(visited[i],false,sizeof(visited[i]));
        }
        //상근이가 갈수있는 곳 초기화
        for (int i = 0; i <= h + 1; i++)
        {
            for (int j = 0; j <= w + 1; j++)
            {
                mp[i][j] = '.';
            }
        }
        for (int i = 1; i <= h; i++)
        {
            cin >> temp;
            for (int j = 1; j <= w; j++)
            {
                mp[i][j] = temp[j-1];
            }
        }
        string key;
        cin >> key;
        if(key=="0"){
            key = "";
        }
        cout << BFS(key)<<endl;
        t--;
    }
    
    
    return 0;
}
