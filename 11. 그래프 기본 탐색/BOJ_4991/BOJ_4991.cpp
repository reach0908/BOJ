#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 21;
const int INF = 1e9;

string mp[MAX];

typedef struct pos{
    int y,x,cnt;
}pos;
int w,h;

int dist[12][12]={-1};

pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pos> point;
int ans;

bool visited[MAX][MAX] = {false};

int BFS(pos a,pos b)
{
    queue<pos> q;
    q.push(a);
    visited[a.y][a.x] = true;
    while (!q.empty())
    {
        int curY = q.front().y;
        int curX = q.front().x;
        int curCnt = q.front().cnt;
        q.pop();
        if(curY==b.y&&curX==b.x){
            return curCnt;
        }
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dir[i].first;
            int nextX = curX + dir[i].second;
            if(0<=nextY&&nextY<h&&0<=nextX&&nextX<w){
                if(!visited[nextY][nextX]){
                    if(mp[nextY][nextX]!='x'){
                        visited[nextY][nextX] = true;
                        q.push({nextY,nextX,curCnt+1});
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
        {
            break;
        }
        memset(dist,0,sizeof(dist));
        point.clear();
        for (int i = 0; i < h; i++)
        {
            cin >> mp[i];
            for (int j = 0; j < w; j++)
            {
                if (mp[i][j] == 'o' || mp[i][j] == '*')
                {
                    point.push_back({i, j});
                }
            }
        }
        //각 포인트별 길이 구해서 그래프 형식으로 만들기
        for (int i = 0; i < point.size() - 1; i++)
        {
            for (int j = i + 1; j < point.size(); j++)
            {
                memset(visited,false,sizeof(visited));
                int temp = BFS(point[i], point[j]);
                dist[i][j] = temp;
                dist[j][i] = temp;
            }
        }
        ans = INF;
        vector<int> dirt;
        for (int i = 0; i < point.size(); i++)
        {
            dirt.push_back(i);
        }
        do
        {
            int sum =0;
            for (int i = 0; i < dirt.size()-1; i++)
            {
                sum += dist[dirt[i]][dirt[i+1]];
            }
            ans = min(sum,ans);
        } while (next_permutation(dirt.begin(),dirt.end()));
        if (ans==INF)
        {
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
        
    }
    return 0;
}
