//
//  main.cpp
//  ABCDE
//
//  Created by KJH on 2020/10/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2001;
bool check = false;
vector<int> v[MAX];
int N,M;
int visited[MAX]={false};
void solve(int n,int cnt){
    if (cnt==5) {
        check = true;
        return;
    }
    if(!check){
        for (int i=0; i<v[n].size(); i++) {
            if (!visited[v[n][i]]) {
                visited[v[n][i]]=true;
                solve(v[n][i],cnt+1);
                visited[v[n][i]]=false;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=0; i<N; i++) {
        solve(i,0);
        if(check){
            break;
        }
    }
    cout << check;
    
    return 0;
}
