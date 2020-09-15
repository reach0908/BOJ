//
//  main.cpp
//  BOJ_1495
//
//  Created by KJH on 2020/09/15.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N,S,M;

int dp[101][1001]={0};
int arr[101];

int main() {
    cin >> N>>S>>M;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    dp[0][S] = 1;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=M; j++) {
            if (dp[i-1][j]==0){
                continue;
            }
                if (j-arr[i]>=0) {
                    dp[i][j-arr[i]]=1;
                }
                if(j+arr[i]<=M){
                    dp[i][j+arr[i]]=1;
                }
        }
    }
    int result = -1;
    for (int i=0; i<=M; i++) {
        if (dp[N][i]==1) {
            result = max(result,i);
        }
    }
    cout << result;
    return 0;
}
