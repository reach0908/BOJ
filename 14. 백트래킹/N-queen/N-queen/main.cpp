//
//  main.cpp
//  N-Queen
//
//  Created by KJH on 2020/09/22.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 15+1;
int N;
int col[MAX];
int result =0;

bool check(int cnt){
    int k=1;
    bool flag=true;
    while(k<cnt&&flag){
        if (col[cnt] == col[k] || abs(col[cnt] - col[k]) == cnt - k)
            flag = false;
        k++;
    }
    return flag;
}
void func(int cnt){
    if(check(cnt)){
        if (N==cnt) {
            result++;
        }
        else{
            for (int i=1; i<=N; i++) {
                col[cnt+1]=i;
                func(cnt+1);
            }
            
        }
    }
}
int main() {
    cin >> N;
    func(0);
    cout << result;
    return 0;
}
