//
//  main.cpp
//  N과M(9)
//
//  Created by KJH on 2020/09/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 9;

vector<int> v;
int N,M;
bool visited[MAX]={false};
int arr[MAX];

void DFS(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int before = -1;
    for (int i=0; i<N; i++) {
        if(!visited[i]&&before!=v[i]){
            visited[i]=true;
            before = v[i];
            arr[cnt] = v[i];
            DFS(cnt+1);
            visited[i]=false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    DFS(0);
    return 0;
}
