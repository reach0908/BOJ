//
//  main.cpp
//  단지구하기(2)
//
//  Created by KJH on 2020/10/07.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 26;

int N;
string arr[MAX];
int visited[MAX][MAX] ={0};
vector<int> res;
int cnt=0;

pair<int, int> moveDir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

void DFS(int y,int x){
    cnt++;
    visited[y][x] = 1;
    for (int i=0; i<4; i++) {
        int nextY = y+moveDir[i].first;
        int nextX = x+moveDir[i].second;
        if (0<=nextX&&nextX<N&&0<=nextY&&nextY<N) {
            if (visited[nextY][nextX]==0&&arr[nextY][nextX]=='1') {
                DFS(nextY, nextX);
            }
            
        }
    }
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j]==0&&arr[i][j]=='1') {
                cnt =0;
                DFS(i,j);
                res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
