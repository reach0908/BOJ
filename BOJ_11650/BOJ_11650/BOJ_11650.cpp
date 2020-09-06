//
//  main.cpp
//  BOJ_11650
//
//  Created by KJH on 2020/09/06.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
vector<pair<int,int>> v;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    v.resize(T);
    for(int i=0;i<T;i++){
        cin >> v[i].first >> v[i].second;
    }
    stable_sort(v.begin(), v.end());
    for (int i=0; i<T; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
