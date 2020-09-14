//
//  main.cpp
//  BOJ_2399
//
//  Created by KJH on 2020/09/14.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    const int nine =9;
    int arr[nine];
    int sum=0;
    for (int i=0;i<nine; i++) {
        cin >> arr[i];
        sum+=arr[i];
    }
    sort(arr, arr+nine);
    int a=0,b=0;
    for (int i=0; i<nine-1; i++) {
        for (int j=i+1; j<nine; j++) {
            if (sum-arr[i]-arr[j]==100) {
                a=i;
                b=j;
            }
        }
    }
    for (int i=0; i<nine; i++) {
        if (a==i||b==i) {
            continue;
        }
        cout << arr[i] << "\n";
    }
    return 0;
}
