#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 10000;
int T;

bool visited[MAX];

void BFS(int A, int B){
    queue<pair<int,string>> q;
    q.push({A,""});
    visited[A] = true;
    while (!q.empty())
    {
        
            int curNum = q.front().first;
            string curChange = q.front().second;
            q.pop();

            if(curNum==B){
                cout << curChange<< endl;
                return;
            }
            else{
                int nextNum = (curNum*2)%MAX;
                if(!visited[nextNum]){
                    q.push({nextNum,curChange+"D"});
                    visited[nextNum] = true;
                }
                nextNum = (curNum-1)<0?9999:curNum-1;
                if (!visited[nextNum])
                {
                    q.push({nextNum,curChange+"S"});
                    visited[nextNum] = true;
                }
                nextNum = (curNum%1000) *10 + curNum/1000;
                if (!visited[nextNum])
                {
                    q.push({nextNum,curChange+"L"});
                    visited[nextNum]=true;
                }
                nextNum=(curNum%10)*1000 + (curNum/10);
                if(!visited[nextNum]){
                    q.push({nextNum,curChange+"R"});
                    visited[nextNum]=true;
                }
            }
        
    }
    

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
     int A,B;
    for (int i = 0; i < T; i++)
    {
        memset(visited,false,sizeof(visited));
        cin >> A >> B;
        BFS(A,B);      
    }
    
    return 0;
}