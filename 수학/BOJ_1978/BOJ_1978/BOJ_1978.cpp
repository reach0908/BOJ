//
//  main.cpp
//  BOJ_1978
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>

const int MAX_SIZE=100;
int arr[MAX_SIZE];

bool primeNum(int num){
    if (num==1) {
        return false;
    }
    for (int i=2; i<num; i++) {
        if (num%i==0) {
            return false;
        }
    }
    return true;
}

using namespace std;
int main() {
    int T;
    cin >> T;
    int pNUM=0;
    for (int i=0; i<T; i++) {
        cin >> arr[i];
        if (primeNum(arr[i])) {
            pNUM++;
        }
    }
    cout << pNUM;
    return 0;
}
