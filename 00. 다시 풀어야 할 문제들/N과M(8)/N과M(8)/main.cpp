//
//  main.cpp
//  N과M(8)
//
//  Created by KJH on 2020/09/24.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 9;


int N,M;

int arr[MAX];
vector<int> v;

void DFS(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++){
            cout << arr[i]<<" ";
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<N;i++){
        if(v[i]>=arr[cnt-1]){
            arr[cnt]=v[i];
            DFS(cnt+1);
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
