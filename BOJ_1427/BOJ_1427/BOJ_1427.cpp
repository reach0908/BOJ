//
//  main.cpp
//  BOJ_1427
//
//  Created by KJH on 2020/09/04.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a,int b){
    return a>b;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    double N;
    vector<int> v;
    
    cin >>N;
    while (1) {
        if (N<1) {
            break;
        }
        int temp;
        temp = (int)N%10;
        v.push_back(temp);
        N = N/10;
    }
    sort(v.begin(), v.end(),compare);
    for (int i=0; i<v.size(); i++) {
        cout << v[i];
    }
    return 0;
}
