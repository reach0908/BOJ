#include <iostream>
#include <cstring>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;
const int MAX = 501;
int T,K;
//부분합
int dp[MAX][MAX];
//0~N까지의 합
int sum[MAX];
vector<int> files;

void func(){
    for (int i = 1; i <= K; i++){
        for (int x = 0; x+i <=K; x++)
        {
            int y = x + i;
            dp[x][y] = INT_MAX;
            for (int mid = x; mid < y; mid++)
            {
                dp[x][y] = min(dp[x][y],dp[x][mid]+ dp[mid+1][y]+sum[y]-sum[x-1]);
            }
            
        } 
    }
}

int main(int argc, char const *argv[])
{
    cin >> T;
    while (T--)
    {
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        files.clear();
        cin >> K;
        for (int i = 1; i <= K; i++)
        {
            int temp;
            cin >> temp;
            files.push_back(temp);
            sum[i] = sum[i-1] + files[i-1]; // 
        }
        func();
        cout << dp[1][K] << endl;
    }
    return 0;
}
