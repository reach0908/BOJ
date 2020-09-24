//
//  main.cpp
//  N과M(10)
//
//  Created by KJH on 2020/09/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 9;

using namespace std;

int N,M;
vector<int> v;
bool visited[MAX];
int arr[MAX];

void DFS(int cnt){
    if (cnt==M) {
        for (int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int before=-1;
    for (int i=0; i<N; i++) {
        if(!visited[i]&&before!=v[i]&&v[i]>=arr[cnt-1]){
            visited[i] = true;
            before=v[i];
            arr[cnt] = v[i];
            DFS(cnt+1);
            visited[i]=false;
            
        }
    }

    
}

int main() {
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    DFS(0);
    
    return 0;
}
