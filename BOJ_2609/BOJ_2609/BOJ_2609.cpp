//
//  main.cpp
//  BOJ_2609
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
        if (a%b == 0)
                 return b;
        return gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
    int a,b;
    cin >>a>>b;
    int gcdNum = gcd(a,b);
    cout << gcdNum << endl << a*b/gcdNum;
    return 0;
}
