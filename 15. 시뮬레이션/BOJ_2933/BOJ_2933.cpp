#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 101;

int R,C,N;

typedef struct Dir
{
    int y,x;
}Dir;

Dir moveDir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

bool flag;
bool visited[MAX][MAX];
vector<Dir> cluster;
vector<int> stick;
string board[MAX];


//DFS로 클러스터가 바닥에 닿았는지 확인

//BFS로 안닿은 클러스터 전부 내려주기

//클러스터가 바닥에 닿아있는지 확인
void DFS(int y,int x){
    if(y==R-1){
        flag=true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + moveDir[i].y;
        int nextX = x + moveDir[i].x;
        if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C||visited[nextY][nextX])
        {
            continue;
        }
        if (board[nextY][nextX] == '.')
        {
            continue;
        }
        visited[nextY][nextX]=true;
        cluster.push_back({nextY,nextX});
        DFS(nextY,nextX);
    }
}

void solve(){
    //막대 주어지고

    //번갈아가면서 던져짐

    //미네랄에 닿을 때까지 해당방향으로 이동

    //미네랄 없애고

    //클러스터 확인

    //클러스터가 바닥에 닿아있는지 확인

    //클러스터가 바닥에 닿아있지않다면 바닥에 닿을 때까지 내리기
    for (int i = 0; i < stick.size(); i++)
    {
        int y = R-stick[i];
        int x = -1;
        if (i%2==0)
        {
            for (int j = 0; j < C; j++)
            {
                if(board[y][j]=='x'){
                    x=j;
                    break;
                }
            }
        }
        else{
            for (int j = C-1; j >=0 ; j--)
            {
                if(board[y][j]=='x'){
                    x=j;
                    break;
                }
            }
        }
        if (x==-1)
        {
            continue;
        }
        board[y][x]='.';
        for (int j = 0; j < 4; j++)
        {
            int nextY = y+moveDir[j].y;
            int nextX = x + moveDir[j].x;
            if(nextY<0||nextY>=R||nextX<0||nextX>=C){
                continue;
            }
            if(board[nextY][nextX]=='.'){
                continue;
            }
            memset(visited,false,sizeof(visited));
            cluster.clear();
            flag=false;

            cluster.push_back({nextY,nextX});
            visited[nextY][nextX]=true;
            DFS(nextY,nextX);

            if(flag){
                continue;
            }
            while (1)
            {
                bool down = true;
                for (int k = 0; k < cluster.size(); k++)
                {
                    board[cluster[k].y][cluster[k].x]='.';
                }
                for (int k = 0; k < cluster.size(); k++)
                {
                    int y = cluster[k].y + 1;
                    int x = cluster[k].x;
                    if (y==R||board[y][x]=='x')
                    {
                        down=false;
                        break;
                    }
                }
                for (int k = 0; k < cluster.size(); k++)
                {
                    if (down)
                    {
                        cluster[k].y++;
                    }
                    board[cluster[k].y][cluster[k].x]='x';
                }
                if (!down)
                {
                    break;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> board[i];
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        stick.push_back(temp);
    }
    solve();
    for (int i = 0; i < R; i++)
    {
        cout << board[i] << endl;
    }
    return 0;
}
