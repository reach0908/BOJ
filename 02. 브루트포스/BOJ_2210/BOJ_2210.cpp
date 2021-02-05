#include <iostream>
#include <vector>
#include <string>

const int MAX = 1000000;
using namespace std;

char board[5][5];
bool visited[MAX]={false};

pair<int,int> moveDir[4] = {{-1,0},{0,1},{1,0},{0,-1}};

void DFS(int y,int x,string num){
    if(num.length()==6){
        if(!visited[stoi(num)]){
            visited[stoi(num)]=true;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + moveDir[i].first;
        int nextX = x + moveDir[i].second;
        if(0<=nextX&&0<=nextY&&nextX<5&&nextY<5){
            num.push_back(board[nextY][nextX]);
            DFS(nextY,nextX,num);
            num.pop_back();
        }
    }
}


int main(int argc, char const *argv[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            string start ="";
            start.push_back(board[i][j]);
            DFS(i,j,start);
        }
    }
    int cnt = 0;
    for (int i = 0; i < MAX; i++)
    {
        if(visited[i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
