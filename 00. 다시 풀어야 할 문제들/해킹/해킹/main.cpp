//
//  main.cpp
//  해킹
//
//  Created by KJH on 2020/09/16.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
#define MAX 10001
using namespace std;

struct Com{
    int dist = INF;
    vector<pair<int, int>> next;
    bool operator < (const Com &c) const {
        return dist > c.dist;
    }
};
Com com[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n, d, c;
        cin >> n >> d >> c;
        for(int i = 1; i <= n; i++){
            com[i].dist = INF;
            com[i].next.clear();
        }
        while(d--){
            int a, b, w;
            cin >> a >> b >> w;
            com[b].next.push_back(make_pair(w, a));
        }
        int count = 1;
        int maxTime = 0;
        priority_queue<Com> pq;
        com[c].dist = 0;
        pq.push(com[c]);
        while(!pq.empty()){
            Com curCom = pq.top();
            pq.pop();
            for(pair<int, int> pa : curCom.next){
                int w = pa.first;
                int nIdx = pa.second;
                if(com[nIdx].dist > curCom.dist + w){
                    if(com[nIdx].dist == INF) count++;
                    com[nIdx].dist = curCom.dist + w;
                    pq.push(com[nIdx]);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            int td = com[i].dist;
            if(td > maxTime && td != INF)
                maxTime = td;
        }
        cout << count << " " << maxTime << '\n';
    }
    return 0;
}
