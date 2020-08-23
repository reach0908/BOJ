//
//  main.cpp
//  BOJ_10430
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int A,B,C;
    cin >> A >> B >> C;
    cout << (A+B)%C << endl << ((A%C) + (B%C))%C <<endl;

    cout << (A*B)%C << endl <<  ((A%C) * (B%C))%C << endl;
    return 0;
}
