#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAX = 51;
const int INF = 1e9;
int N,M;

int city[MAX][MAX];

int chicken[MAX][MAX][13+1];

typedef struct pos{
    int y,x;
}pos;

vector<pos> home;
vector<pos> cHouse;
vector<int> closeNum;

int distance(pos a,pos b){
    return abs(a.y-b.y) + abs(a.x-b.x);
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> city[i][j];
            if(city[i][j]==1){
                home.push_back({i,j});
            }
            if(city[i][j]==2){
                cHouse.push_back({i,j});
            }
        }
    }
    for (int j = 0; j < M; j++)
    {
        closeNum.push_back(0);
    }
    for (int j = M; j < cHouse.size(); j++)
    {
        closeNum.push_back(1);
    }
    int result = INF;
    do
    {
        int tempResult = 0;
        for (int k = 0; k < home.size(); k++)
        {
            int dist = INF;
            for (int i = 0; i < closeNum.size(); i++)
            {
                
                if(closeNum[i]==0){
                    dist = min(dist,distance(cHouse[i],home[k]));
                }
            }
            tempResult += dist;
        }
        result = min(tempResult,result);
    } while (next_permutation(closeNum.begin(), closeNum.end()));
    cout << result;

    return 0;
}
