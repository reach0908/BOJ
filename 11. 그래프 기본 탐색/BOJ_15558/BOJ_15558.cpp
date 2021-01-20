#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;


int N,K;
int arr[2][MAX]={0};
bool visited[2][MAX]={false};

pair<int,int> dir[4] = {{0,-1},{0,1},{-1,0},{1,0}};

void BFS(){
    bool flag = false;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});
    visited[0][0]=true;
    
    while (!q.empty()&&!flag)
    {
        int curTime = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();
         if (curX>=N)
        {
            flag=true;
            break;
        }
        if(curTime>=N){
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dir[i].first;
            int nextX = curX + dir[i].second;
            if(nextY>=0&&nextX>curTime&&nextY<2&&nextX<N){
                if(arr[nextY][nextX]==1&&visited[nextY][nextX]==false){
                     q.push({curTime+1,{nextY,nextX}});
                     visited[curY][curX] = true;
                }
            }
        }
    }
    if(flag){
        cout << 1;
    }
    else {
        cout << 0;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < 2; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            arr[i][j]=temp[j]-'0';
        }
    }
    dir[2].second=K;
    dir[3].second=K;
    BFS();
    return 0;
}