//
//  main.cpp
//  1,2,3더하기
//
//  Created by KJH on 2020/09/15.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int result[11] = {0,1,2,4,7,0};


int func(int num) {
    if (num==1||num==2||num==3) {
        return result[num];
    }
    else {
        return result[num]=func(num - 1) + func(num - 2) + func(num - 3);
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }
    for (int i=0; i<N; i++) {
        cout << func(v[i]) << endl;
    }
    return 0;
}
