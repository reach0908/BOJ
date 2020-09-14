//
//  main.cpp
//  Calender
//
//  Created by KJH on 2020/09/14.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int E,S,M;
    cin >> E >> S>>M;
    int a=0,b=0,c=0;
    int t=1;
    while (1) {
        a++;
        b++;
        c++;
        if (a==E&&b==S&&c==M) {
            break;
        }
        a=a%15;
        b=b%28;
        c=c%19;
        t++;
    }
    cout << t;
    return 0;
}
