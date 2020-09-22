//
//  main.cpp
//  평범한배낭
//
//  Created by KJH on 2020/09/21.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K,w,v;
int arr[102][100003];
int main() {
    
    cin >> N >> K;
    vector<pair<int, int>> wv;
    
    wv.push_back(make_pair(0, 0));
    for (int i=1; i<=N; i++) {
        cin >> w >> v;
        wv.push_back(make_pair(w,v));
    }
    for (int i=1; i<=N; i++) {
        int weight = wv[i].first;
        int value = wv[i].second;
        for (int j=0; j<=K; j++) { //가능한 모든 무게에 대해 경우의수를 찾는다
            if (j<wv[i].first) {
                arr[i][j]=arr[i-1][j];
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[i-1][j-weight]+value);
            }
        }
    }
    cout << arr[N-1][K];
    return 0;
}
