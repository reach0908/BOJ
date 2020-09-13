//
//  main.cpp
//  BOJ_1766
//
//  Created by KJH on 2020/09/13.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAX = 32000+1;

int N,M;
int intDegree[MAX];
vector<int> graph[MAX];
priority_queue<int, vector<int>,greater<int>> pq;

//힙구조와 위상정렬을 이용해 문제를 푼다

//위상정렬은 순서가 정해져있는 작업을 차례로 수행할 때, 순서를 결정해주는 알고리즘
//위상정렬 알고리즘
//1.진입차수가 0인 정점을 큐에 삽입한다.
//2.큐에서 원소를 꺼내 해당 원소와 간선을 제거
//3. 제거 이후 진입 차수가 0이 된 정점을 큐에 삽입
//4. 큐가 빌때까지 2-3 과정을 반복

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a>>b;
        intDegree[b]++;
        graph[a].push_back(b);
    }
    for (int i=1; i<=N; i++) {
        if (intDegree[i]==0) {
            pq.push(i);
        }
    }
    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        cout << node << " ";
        for (int i=0; i<graph[node].size(); i++) {
            int nextNode = graph[node][i];
            if (--intDegree[nextNode]==0) {
                pq.push(nextNode);
            }
        }
    }
    cout<<"\n";
    return 0;
}







