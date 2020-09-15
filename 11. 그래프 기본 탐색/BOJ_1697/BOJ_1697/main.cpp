//
//  main.cpp
//  BOJ_1697
//
//  Created by KJH on 2020/09/15.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 100001;
bool visited[MAX];

int BFS(int start,int dest){

    queue<pair<int,int>> q;
    //페어의 두번째 인자는 시간초로 활용
    q.push(make_pair(start, 0));
    visited[start] = true;
    
    while (!q.empty()) {
        int curLoc = q.front().first;
        int cursec = q.front().second;
        q.pop();
        if (curLoc==dest) {
            return cursec;
        }
       //BFS와 다르게 포문을 돌리지 않는다
        // - 이미 만들어진 그래프가 없기때문에 만들어나가면서 확인
        if (curLoc + 1 < MAX && !visited[curLoc + 1]){
            q.push(make_pair(curLoc+1, cursec+1));
            visited[curLoc+1]=true;
        }
        if (curLoc - 1 >= 0 && !visited[curLoc - 1]){
            q.push(make_pair(curLoc-1, cursec+1));
            visited[curLoc-1]=true;
        }
        if (curLoc * 2 < MAX && !visited[curLoc*2]){
            q.push(make_pair(curLoc*2, cursec+1));
            visited[curLoc*2]=true;
        }
    }
    //페어에 새로운 값을 넣을때는 make pair
    return -1;
}



int main() {
    int N,K;
    cin >> N >> K;
    cout << BFS(N,K);
    return 0;
}
