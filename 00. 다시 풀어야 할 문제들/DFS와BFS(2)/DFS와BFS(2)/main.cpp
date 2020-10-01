//
//  main.cpp
//  DFS와BFS(2)
//
//  Created by KJH on 2020/10/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

const int MAX = 1001;

using namespace std;
int N,M,V;
vector<int> v[MAX];
bool visited[MAX]={false};
int arr[MAX];

void DFS(int start){
    cout << start << " ";
    
    for(int i=0;i<v[start].size();i++){
        if(!visited[v[start][i]]){
            visited[v[start][i]]=true;
            DFS(v[start][i]);
        }
        
    }
}
void BFS(int start){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int cur= q.front();
        cout << cur << " ";
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            if(!visited[v[cur][i]]){
                q.push(v[cur][i]);
                visited[v[cur][i]]=true;
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
  
    cin >> N >> M >> V;
    int a,b;
    for (int i=0; i<M; i++) {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<N;i++){
        sort(v[i].begin(),v[i].end());
    }
    visited[V]=true;
    DFS(V);
    cout << "\n";
    memset(visited, false, sizeof(visited));
    BFS(V);
    
    return 0;
}
