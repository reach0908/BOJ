//
//  main.cpp
//  BOJ_1476
//
//  Created by KJH on 2020/09/14.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int earth,sun,moon;
    cin >> earth >> sun >> moon;
    int E=1,S=1,M=1;
    int year =1;
    while (1) {
        if (E>15) {
                   E=1;
               }
               if (S>28) {
                   S=1;
               }
               if (M>19) {
                   M=1;
               }
        if (E==earth&&sun==S&&M==moon) {
            break;
        }
       
        year++;
        E++;
        S++;
        M++;
    }
    cout << year;
    return 0;
}
