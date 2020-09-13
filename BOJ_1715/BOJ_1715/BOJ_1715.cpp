//
//  main.cpp
//  BOJ_1715
//
//  Created by KJH on 2020/09/13.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<int,vector<int>,greater<int>> pq;
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    int a,b,temp;
    int result=0;
    while (pq.size()>1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        temp = a+b;
        result += temp;
        pq.push(temp);
    }
    cout << result;
    return 0;
}
