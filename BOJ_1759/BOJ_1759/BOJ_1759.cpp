//
//  main.cpp
//  BOJ_1759
//
//  Created by KJH on 2020/08/29.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){ return a > b; }

int main() {
    
    int t;
    int k;
    cin >> t>> k;
    
    vector<char> v(k);
    vector<int> ind;
    
    for (int i=0; i<k; i++) {
        cin >> v[i];
    }
    
    for(int i=0; i<t; i++){
        ind.push_back(0);
    }
    for(int i=0; i<k-t; i++){
        ind.push_back(1);
    }
    sort(ind.begin(),ind.end());
    sort(v.begin(), v.end());
    
    do{
        vector<char> temp;
        int acount=0;
        int elscount =0;
        
        for (int i=0; i<k; i++) {
            if (ind[i]==0) {
                if(v[i]=='a'||v[i]=='e'||v[i]=='i'||v[i]=='o'||v[i]=='u') {
                    acount++;
                }
                else{
                    elscount++;
                }
                temp.push_back(v[i]);
            }
        }
        if (acount<1||elscount<2) {
            continue;
        }
        for (int i=0; i<t; i++) {
            cout << temp[i];
        }
        cout << endl;
        
    }while (next_permutation(ind.begin(), ind.end()));
    
    return 0;
}
    
