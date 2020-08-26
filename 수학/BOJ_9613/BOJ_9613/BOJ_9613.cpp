//
//  main.cpp
//  BOJ_9613
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 100;
int arr[MAX];

int GCD(int a, int b)
{
        if (a%b == 0)
                 return b;
        return GCD(b, a%b);
} //예외처리를 잘못하여 첫 제출시 틀림 , 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    
    for (int i=0; i<T; i++) {
        int num;
        cin>>num;
        long long sum=0;
        for (int j=0; j<num; j++) {
            cin >> arr[j];
        }
        for (int j=0; j<num; j++) {
            for (int k=j+1; k<num; k++) {
                sum+=GCD(arr[j],arr[k]);
            }
        }
        cout << sum<<endl;
    }
    return 0;
}
