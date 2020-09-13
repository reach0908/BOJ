//
//  main.cpp
//  BOJ_1927
//
//  Created by KJH on 2020/09/13.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>,greater<int>> pq;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        
        if (!num&&pq.empty()) {
            cout << 0 << "\n";
        }
        else if (!num){
            cout << pq.top() << "\n";
            pq.pop();
        }
        else{
            pq.push(num);
        }
    }
    return 0;
}

//최소 힙 구현에 우선순위 큐를 쓰는 이유?
// 우선순위 큐는 기본적으로 힙을 이용한 자료구조이다.
