//
//  main.cpp
//  알파벳
//
//  Created by KJH on 2020/09/22.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int R,C;
const int MAX = 21;
string result;
char c[MAX][MAX];
pair<int, int> dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visit[26]={false};

int maxResult =0;
void DFS(int y,int x,int cnt){
    maxResult = max(maxResult, cnt);
    for (int i=0; i<4; i++) {
        int nextX =x+dir[i].second;
        int nextY =y+dir[i].first;
        if (0 <= nextY && nextY < R && 0 <= nextX && nextX < C){
            if (!visit[c[nextY][nextX]-'A']) {
                visit[c[nextY][nextX]-'A']=true;
                DFS(y+dir[i].first, x+dir[i].second,cnt+1);
                visit[c[nextY][nextX]-'A']=false;
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin>>c[i][j];
        }
    }
    visit[c[0][0]-'A']=true;
    DFS(0,0,1);
    cout << maxResult;
    return 0;
}
