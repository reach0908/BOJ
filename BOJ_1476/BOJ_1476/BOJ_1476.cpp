//
//  main.cpp
//  BOJ_1476
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
using namespace std;

// 1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19  // 최소공배수는 7980
int main() {
    int a,b,c;
    int e,s,m;
    int t=1;
    
    cin >> e >> s >> m;
    a=0;b=0;c=0;
    while (1) {
        a++;b++;c++;
        if (a==e&&b==s&&c==m) {
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
