//
//  main.cpp
//  거스름돈
//
//  Created by KJH on 2020/09/17.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>

using namespace std;

const int taro=1000;

int coin[6]={500,100,50,10,5,1};

int main() {
    int N;
    cin >> N;
    N=taro-N;
    int count =0;
    for (int i=0; i<6; i++) {
        count += (int)N/coin[i];
        N = N%coin[i];
    }
    cout << count;
    return 0;
}
