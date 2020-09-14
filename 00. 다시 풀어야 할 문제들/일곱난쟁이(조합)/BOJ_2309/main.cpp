//
//  main.cpp
//  BOJ_2309
//
//  Created by KJH on 2020/09/14.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    const int seven=7;
    const int NINE=9;
    vector<int> height;
    
    for (int i=0; i<NINE; i++) {
        int temp;
        cin >> temp;
        height.push_back(temp);
    }
    sort(height.begin(), height.end());
    vector<int> confirm;
    
    for (int i=0; i<seven; i++) {
        confirm.push_back(0);
    }
    for (int i=0; i<NINE-seven; i++) {
        confirm.push_back(1);
    }
    
    sort(confirm.begin(), confirm.end());
    do{
        int sum =0;
        for (int i=0; i<NINE; i++) {
            if (confirm[i]==0) {
                sum+=height[i];
            }
        }
        if (sum==100) {
            for (int i=0; i<NINE; i++) {
                if (confirm[i]==0) {
                    cout << height[i] << "\n";
                }
            }
            return 0;
        }
    }while (next_permutation(confirm.begin(), confirm.end()));
    
}
