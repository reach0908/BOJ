//
//  main.cpp
//  BOJ_2609
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int a,int b){
    int c;
    if (a<b) {
        int temp = a;
        a=b;
        b=temp;
    }
    while (b!=0) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main(int argc, const char * argv[]) {
    int a,b;
    cin >>a>>b;
    int gcdNum = gcd(a,b);
    cout << gcdNum << endl << a*b/gcdNum;
    return 0;
}
