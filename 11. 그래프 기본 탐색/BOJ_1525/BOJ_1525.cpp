#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

const int MAX = 3;
int board[MAX][MAX];


pair<int,int> moveDir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
string target = "123456780";
map<string,int> visited;
void BFS(string start)
{
    queue<pair<int, string>> q;
    q.push({0, start});
    while (!q.empty())
    {

        int curCnt = q.front().first;
        string curStr = q.front().second;
        q.pop();
        if (curStr == target)
        {
            cout << curCnt;
            return;
        }
        int nine = curStr.find('0');
        int curY = nine/3;
        int curX = nine%3;

        for (int i = 0; i < 4; i++)
        {
            int nextY = moveDir[i].first+curY;
            int nextX = moveDir[i].second+curX;
            if (0<=nextY&&nextY<MAX&&0<=nextX&&nextX<MAX)
            {
                string temp = curStr;
                swap(temp[curY*3+curX],temp[nextY*3+nextX]);
                if(!visited.count(temp)){
                    visited[temp]=1;
                    q.push({curCnt+1,temp});
                }

            }
        }
    }
    cout << -1;
}

int main(int argc, char const *argv[])
{
    string start="";
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            int num;
            cin >> num;
            start +=to_string(num);
        }
    }
    BFS(start);
    return 0;
}
