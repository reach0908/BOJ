//
//  main.cpp
//  BOJ_11004
//
//  Created by KJH on 2020/09/10.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,K;
    cin >> T >> K;
    num.resize(T);
    for (int i=0; i<T; i++) {
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    cout << num[K-1];
    return 0;
}
