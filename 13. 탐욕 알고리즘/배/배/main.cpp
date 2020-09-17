//
//  main.cpp
//  배
//
//  Created by KJH on 2020/09/17.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;

vector<int> crane;
priority_queue<int, vector<int>> box;

int main() {
    cin >> N;
    crane.resize(N);
    for (int i=0; i<N; i++) {
        cin >> crane[i];
    }
    cin >> M;
    for (int i=0; i<M; i++) {
        int temp;
        cin >> temp;
        box.push(temp);
    }
    sort(crane.begin(), crane.end(),greater<>());
    cout << box.top();
    if (crane[0]<box.top()) {
        cout<<-1;
    }else{
        int countN =0;
        while (!box.empty()) {
            for (int i=0; i<N; i++) {
                if (crane[i]>=box.top()) {
                    box.pop();
                }
            }
            cout << countN;
            countN++;
        }
        cout << countN;
    }
    return 0;
}
