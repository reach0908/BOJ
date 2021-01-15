#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 102;
const int INF = 1e9;
int board[MAX][MAX];
bool visited[MAX][MAX]={false};

typedef struct options
{
    int doorCnt;
    int pCnt;
    int y;
    int x;
}options;

int t,h,w;
pair<int,int> moveDir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

int BFS(){
   
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> h >> w;
        for (int j = 0; j < MAX; j++)
        {
            memset(board[j],-1,sizeof(board[j]));
            memset(visited[j],false,sizeof(visited[j]));
        }
        
        for (int j = 1; j <= h; j++)
        {
            string temp;
            cin >> temp;
            for (int k = 1; k <= w; k++)
            {
                if (temp[k] == '*')
                {
                    board[j][k] = 0;
                }
                else if (temp[k] == '.')
                {
                    board[j][k] = 1;
                }
                else if (temp[k] == '$')
                {
                    board[j][k] = 2;
                }
                else if (temp[k] == '#')
                {
                    board[j][k] = 3;
                }
            }
        }
        cout << BFS() << endl;
    }

    return 0;
}
