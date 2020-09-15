//
//  main.cpp
//  다음순열
//
//  Created by KJH on 2020/09/15.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }
    if(next_permutation(v.begin(), v.end())){
    for (int i=0; i<N; i++) {
        cout << v[i] << " ";
        
    }
        
    }
    else{
        cout << -1;
    }
    return 0;
}
