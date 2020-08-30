//
//  main.cpp
//  BOJ_1182
//
//  Created by KJH on 2020/08/29.
//  Copyright © 2020 KJH. All rights reserved.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;

int main() {
    int t,k;
    cin >> t >> k;
    
    vector<int> num;
   
    int n;
    for (int i=0; i<t; i++) {
        cin >> n;
        num.push_back(n);
    }
    for (int j=1; j<=t; j++) {
        vector<int> comb;
        for (int i=0; i<j; i++) {
            comb.push_back(0);
        }
        for (int i=0; i<t-j; i++) {
            comb.push_back(1);
        }
        sort(comb.begin(), comb.end());
        do {
            int sum =0;
            for (int i=0; i<comb.size(); i++) {
                if (comb[i]==0) {
                    sum += num[i];
                }
            }
            result.push_back(sum);
        } while (next_permutation(comb.begin(),comb.end()));
    }
    int count =0;
    for (int i=0; i<result.size();i++ ) {
        if (result[i]==k) {
            count++;
        }
    }
    cout << count;
    return 0;
}
