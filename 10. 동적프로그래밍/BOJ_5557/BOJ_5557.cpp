#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 101;
int N;
 dp[MAX][21]={0};
int arr[MAX];

int start,last;

void solve(){

    for (int i = 2; i <= N-1; i++)
    {
        for (int j = 0; j <=20; j++)
        {
            if(dp[i-1][j]==0){
                continue;
            }
            if(j-arr[i]>=0){
                dp[i][j-arr[i]]+=dp[i-1][j];
            }
            if(j+arr[i]<=20){
                dp[i][j+arr[i]]+=dp[i-1][j];
            }
            
        }
    }
}
int main()
{
    cin >> N;
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        if(i==1){
            start = arr[i];
        }
        if(i==N){
            last = arr[i];
        }
    }
    dp[1][start]=1;
    solve();
    cout << dp[N-1][last];
    return 0;
}
