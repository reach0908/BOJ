//
//  main.cpp
//  BOJ_1934
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
 
using namespace std;

int gcd(int a,int b){
    int c;
    if(a<b){
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
    //유클리드호제법이용
}
 
int main(){
    int T,a,b;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> a >> b;
        cout << (a*b)/gcd(a,b) << endl;
    }
    return 0;
}
