//
//  main.cpp
//  이분그래프(2)
//
//  Created by KJH on 2020/10/07.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 20001;

int K,V,E;

vector<int> arr[MAX];
int nodeColor[MAX];

void DFS(int n,int color){
    nodeColor[n] = color;
    for (int i=0; i<arr[n].size(); i++) {
        int next = arr[n][i];
        if (!nodeColor[next]) {
            DFS(next,3-color);
        }
    }
}

bool checkColor(){
    for(int i=1;i<=V;i++){
        for (int j=0; j<arr[i].size(); j++) {
            int next = arr[i][j];
            if(nodeColor[i]==nodeColor[next]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    
    cin >> K;
    for(int i=0;i<K;i++){
        cin >> V >> E;
        memset(nodeColor, 0, sizeof(nodeColor));
        for (int j = 1; j < MAX; j++){
            arr[j].clear();
        }
        for(int j=0;j<E;j++){
            int a,b;
            cin >> a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for (int j=1; j<=V; j++) {
            if(!nodeColor[j]){
                DFS(j,1);
            }
        }
        if(checkColor()){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
