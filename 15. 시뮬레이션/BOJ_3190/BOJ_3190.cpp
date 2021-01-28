#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>

using namespace std;
const int MAX = 101;

int N,K;
int board[MAX][MAX]={0};
bool visited[MAX][MAX]={false};
queue<pair<int,int>> arr;

pair<int,int> moveDir[4]= {{0,1},{1,0},{0,-1},{-1,0}};

void solve(){
    int cnt=0;
    deque<pair<int,int>> dq;
    dq.push_front({0,0});
    int dir =0;
    visited[0][0] = true;
    while (1)
    {
        cnt++;
        pair<int,int> next = {dq.front().first + moveDir[dir].first,
        dq.front().second+moveDir[dir].second};
        if(visited[next.first][next.second]||
            next.first<0||next.first>=N||next.second<0||next.second>=N){
            cout << cnt << endl;
            break;
        }
        visited[next.first][next.second]=true;
        dq.push_front(next);
        if (board[next.first][next.second]==1)
        {
            board[next.first][next.second]=0;
        }else{
            pair<int,int> tail = dq.back();
            visited[tail.first][tail.second]=false;
            dq.pop_back();
        }
        if (!arr.empty() && arr.front().first == cnt)
        {
            if (arr.front().second == 'D')
            {
                dir = (dir + 1) % 4;
            }
            else
            {
                dir = (dir + 3) % 4;
            }
            arr.pop();
        }
    }
}
int main(int argc, char const *argv[])
{

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x,y;
        cin >> y >> x;
        board[y-1][x-1]=1;
    }
    int R;
    cin >> R;
    for (int i = 0; i < R; i++)
    {
        int cnt;
        char dir;
        cin >> cnt >> dir;
        if(dir=='D'){
            //오른쪽
            arr.push({cnt,0});
        }
        else if(dir=='L'){
            //왼쪽
            arr.push({cnt,1});
        }
    }
    solve();
    return 0;
}
