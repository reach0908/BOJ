#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10001;

int n,k;
long long dp[MAX];
vector<int> coin;

void solve(){
    dp[0]=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j <=k; j++)
        {
            dp[j]=dp[j]+dp[j-coin[i]];
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coin.push_back(temp);
    }
    solve();
    cout << dp[k];
    return 0;
}
