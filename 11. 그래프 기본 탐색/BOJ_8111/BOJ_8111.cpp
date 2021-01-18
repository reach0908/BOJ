#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 20000+1;
int t,n;
bool visited[MAX];
pair<int,char> arr[MAX];

void BFS(){
    queue<int> q;
    q.push(1);
    visited[1]=true;
    arr[1].first=-1;
    arr[1].second='1';
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        int p[2];
        p[0]= (temp*10)%n;
        p[1] = (p[0]+1)%n;

        for (int i = 0; i < 2; i++)
        {
            if(!visited[p[i]]){
                arr[p[i]].first=temp;
                arr[p[i]].second=i+'0';
                if(!p[i]){
                    return;
                }
                visited[p[i]]=true;
                q.push(p[i]);
            }
        }
    }
}

void printPath(int num){
    if(num==-1){
        return;
    }
    printPath(arr[num].first);
    cout << arr[num].second;
}
int main(int argc, char const *argv[])
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        memset(visited,false,sizeof(visited));
        BFS();
        printPath(0);
        cout << endl;
    }
    return 0;
}
