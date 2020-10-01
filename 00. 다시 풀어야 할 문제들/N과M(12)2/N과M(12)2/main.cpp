//
//  main.cpp
//  N과M(12)2
//
//  Created by KJH on 2020/10/02.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 9;

vector<int> v;
int arr[MAX] = {-1};
int N, M;
bool check[10001] = { false };

void DFS(int cnt) {
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if(arr[cnt-1]<=v[i]){
            arr[cnt] = v[i];
            
            DFS(cnt + 1);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if(!check[temp]){
            check[temp]=true;
            v.push_back(temp);
        }
        
    }
    sort(v.begin(), v.end());
    DFS(0);

    return 0;
}

