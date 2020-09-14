//
//  main.cpp
//  BOJ_12865
//
//  Created by KJH on 2020/09/14.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N,K;

int dp[102][100000+1]={0};


int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    pair<int,int> box[N];
    for (int i=0; i<N; i++) {
        cin >> box[i].first >> box[i].second;
    }
    for (int i=1; i<=N; i++) {
        int weight = box[i].first;
        int value = box[i].second;
        for (int j=0; j<=K; j++) {
            if (j<box[i].first) {
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight]+value);
                
            }
        }
    }
    cout << dp[N][K];
    return 0;
}
