#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

const int MAX = 20;
const int INF = 1e9;
using namespace std;

int N;
int score[MAX][MAX];
bool visited[MAX][MAX];
vector<int> team;

int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> score[i][j];
        }
    }
    for (int i = 0; i < N/2; i++)
    {
        team.push_back(0);
    }
    for (int i = N/2; i < N; i++)
    {
        team.push_back(1);
    }
    int result = INF;
    do
    {
        int scoreStart=0;
        int scoreLink=0;
        vector<int> start;
        vector<int> link;
        for (int i = 0; i < team.size(); i++)
        {
            if(team[i]==1){
                start.push_back(i);
            }else{
                link.push_back(i);
            }
        }
        for (int i = 0; i < start.size()-1; i++)
        {
            for (int j = i+1; j < start.size(); j++)
            {
                scoreStart += score[start[i]][start[j]]+score[start[j]][start[i]];   
            }
        }
        for (int i = 0; i < link.size()-1; i++)
        {
            for (int j = i+1; j < link.size(); j++)
            {
                scoreLink += score[link[i]][link[j]] + score[link[j]][link[i]];   
            }
        }
        result = min(result,abs(scoreStart-scoreLink));
    } while (next_permutation(team.begin(),team.end()));
    cout << result;
    return 0;
}
