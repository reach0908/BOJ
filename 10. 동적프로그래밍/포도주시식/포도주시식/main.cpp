//
//  main.cpp
//  포도주시식
//
//  Created by KJH on 2020/12/24.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N;

const int MAX = 10001;

int table[MAX]={0};
long long cache[MAX] = {0};


long long solve(){
    cache[0] = 0;
    cache[1] = table[1];
    cache[2] = table[1] + table[2];
    for (int i=3; i<=N; i++) {
        cache[i] = max(cache[i-3]+table[i-1],cache[i-2])+table[i];
        cache[i]= max(cache[i-1],cache[i]);
    }
    
    return cache[N];
}

int main() {
    
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> table[i];
    }
    
    cout << solve();
    return 0;
}
