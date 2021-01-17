#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 101;
const int INF = 987654321;
int W,H;

typedef struct pos{
    int y,x,mCnt,prevDir;
}pos;

string mp[MAX];
vector<pos> point;
int visited[MAX][MAX];
pair<int,int> dir[4] = {{-1,0},{0,1},{1,0},{0,-1}};
struct cmp
{
    bool operator()(pos a,pos b){
        return a.mCnt>b.mCnt;
    }
};
int dist[MAX][MAX][4]={INF};
int BFS(){
    //이전방향 저장해두고 방향바뀌면 거울갯수증가!
    queue<pos> q;
    for (int i = 0; i < 4; i++)
    {
        q.push({point[0].y,point[0].x,0,i});
    }
    visited[point[0].y][point[0].x]=0;
    while (!q.empty())
    {
        int curY = q.front().y;
        int curX = q.front().x;
        int curCnt = q.front().mCnt;
        int curDir = q.front().prevDir;
        q.pop();
        for (int i = 0; i <4; i++)
        {
            int nextY = curY + dir[i].first;
            int nextX = curX + dir[i].second;
            int nextCnt = curCnt;
            if(nextY>=H||nextY<0||nextX<0||nextX>=W){
                continue;
            }
            if(mp[nextY][nextX]=='*'){
                continue;
            }
            if(curDir!=i){
                nextCnt+=1;
            }
            if(visited[nextY][nextX]>=nextCnt){
                visited[nextY][nextX]=nextCnt;
                q.push({nextY,nextX,nextCnt,i});
            }
        }
    }
    return visited[point[1].y][point[1].x];
}
int main()
{
    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        cin >> mp[i];
        for (int j = 0; j < W; j++)
        {
            if(mp[i][j]=='C'){
                point.push_back({i,j});
            }
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                visited[i][j]= INF;
            }
            
        }
        
    }
    cout << BFS();
    return 0;
}
