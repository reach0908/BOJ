#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 101;
int N,K;

pair<int,int> wv[MAX];
int dp[MAX][100001];
void solve(){

}

int main(int argc, char const *argv[])
{
    cin >> N >> K;
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        cin >> wv[i].first >> wv[i].second;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <=K; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=wv[i].first){
                dp[i][j] = max(dp[i][j],dp[i-1][j-wv[i].first]+wv[i].second);
            }
        }
    }
    cout << dp[N][K];
    return 0;
}
