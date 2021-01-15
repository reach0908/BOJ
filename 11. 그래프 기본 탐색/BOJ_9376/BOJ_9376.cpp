#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 102;
const int INF = 1e9;

string board[MAX];

typedef struct options{
    int y,x,val;
}options;
struct cmp
{
    bool operator()(options a,options b){
        return a.val > b.val;
    }
};

int t,h,w;
pair<int,int> moveDir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
int res[3][MAX][MAX];
bool visited[MAX][MAX];

vector<options> point;

void BFS(int y, int x, int num)
{
    priority_queue<options, vector<options>, cmp> q;
    
    q.push({y,x,0});
    visited[y][x] = true;
    res[num][y][x] =0;

    while (!q.empty())
    {
        options op = q.top();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextY = op.y + moveDir[i].first;
            int nextX = op.x + moveDir[i].second;
            int curval = op.val;
            if(nextY<0||nextY>h+1||nextX<0||nextX>w+1){
                continue;
            }
            if(visited[nextY][nextX]||board[nextY][nextX]=='*'){
                continue;
            }
            if(board[nextY][nextX]=='#'){
                curval++;
            }
            q.push({nextY,nextX,curval});
            visited[nextY][nextX]=true;
            res[num][nextY][nextX]=curval;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t>0)
    {
        memset(visited,false,sizeof(visited));
        memset(res,0,sizeof(res));
        point.clear();
        point.push_back({0,0}); 

        for (int i = 0; i < MAX; i++)
        {
            board[i].clear();
        }
        cin >> h >> w;
        for (int i = 0; i < w+2; i++)
        {
            board[0] += '.';
            board[h+1] += '.';
        }
        for (int i = 1; i <= h; i++)
        {
            cin >> board[i];
            board[i] = '.' + board[i];
            for (int j = 1; j <=w; j++)
            {
                if(board[i][j]=='$'){
                    point.push_back({i,j});
                }
            }
            board[i] += '.';
        }
        for (int i = 0; i <3; i++)
        {
            for (int j = 0; j <=h; j++)
            {
                for (int k = 0; k <= w; k++)
                {
                    res[i][j][k]=INF;
                }
            }
            
        }
        for (int i = 0; i < 3; i++)
        {
            BFS(point[i].y,point[i].x,i);
        }
        
        long long ans = INF;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <=w; j++)
            {
                if(board[i][j]=='*'){
                    continue;
                }
                long long tmp =0;
                for (int k = 0; k < 3; k++)
                {
                    tmp += res[k][i][j];
                }
                if(board[i][j]=='#'){
                    tmp-=2;
                }
                ans = min(ans,tmp);
            }
        }
        cout << ans << endl;
        t--;
    }
    return 0;
}
