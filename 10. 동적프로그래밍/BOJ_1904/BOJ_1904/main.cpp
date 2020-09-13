//
//  main.cpp
//  BOJ_1904
//
//  Created by KJH on 2020/09/13.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
using namespace std;

#define MOD 15746

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, i;

    cin >> N;
    long long result[N+1];
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;

    for (i = 3; i <= N; i++ ) result[i] = (result[i-1] + result[i-2]) % MOD;
    cout << result[N];

    return 0;
}
