#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 101;
typedef struct options{
    //끝점
    int y,x;
    //지금까지의 방향
    vector<int> dir;
}options;

int N;
pair<int,int> moveDir[4] = {{0,1},{-1,0},{0,-1},{1,0}};
bool visited[MAX][MAX]={false};
//정사각형 몇개인지 세는 함수
int check(){
    int cnt = 0;
    for (int i = 0; i < MAX-1; i++)
    {
        for (int j = 0; j < MAX-1; j++)
        {
            if(visited[i][j]&&visited[i+1][j]&&visited[i][j+1]&&visited[i+1][j+1]){
                cnt++;
            }
        }
    }
    return cnt;
}
//BFS
void solve(int y,int x,int d,int g){
    vector<int> curve;
    curve.push_back(d);
    for (int i = 0; i < g; i++)
    {
        vector<int> temp = curve;
        for (int j = temp.size()-1; j >=0; j--)
        {
            curve.push_back((temp[j]+1)%4);
        }
    }
    visited[y][x] = true;
    for (int i = 0; i < curve.size(); i++)
    {
        y += moveDir[curve[i]].first;
        x += moveDir[curve[i]].second;
        if(y>=0&&y<MAX&&x>=0&&x<MAX){
            visited[y][x]=true;
        }
    }
}


int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        solve(y,x,d,g);
    }
    cout << check() << endl;
    return 0;
}
