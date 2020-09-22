//
//  main.cpp
//  BOJ_12865
//
//  Created by KJH on 2020/09/13.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result[100];
pair<int,int> box[100];
int N,K;

int main() {
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        int a,b;
        cin >> a>> b;
        box[i].first=a;
        box[i].second=b;
    }
    
    
}
