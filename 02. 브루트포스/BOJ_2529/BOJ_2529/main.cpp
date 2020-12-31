//
//  main.cpp
//  BOJ_2529
//
//  Created by KJH on 2021/01/01.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> maxNum;
vector<int> minNum;

vector<char> b;

int K;
bool check(vector<int> &v){
    for (int i=0; i<b.size(); i++) {
        if(b[i]=='<'&& v[i]>v[i+1]){
            return false;
        }else if(b[i]=='>'&&v[i]<v[i+1]){
            return false;
        }
    }
    return true;
}

void solve(){
    for(int i=9;i>9-(K+1);i--){
        maxNum.push_back(i);
    }
    while (!check(maxNum)) {
        prev_permutation(maxNum.begin(), maxNum.end());
    }
    for(int i=0;i<K+1;i++){
        minNum.push_back(i);
    }
    while(!check(minNum)){
        next_permutation(minNum.begin(), minNum.end());
    }
}

int main() {

    cin >> K;
    for(int i=0;i<K;i++){
        char temp;
        cin >> temp;
        b.push_back(temp);
    }
    solve();
    for (int i=0; i<maxNum.size(); i++) {
        cout << maxNum[i];
    }
    cout << endl;
    for(int i=0; i<minNum.size();i++){
        cout << minNum[i];
    }
    return 0;
}
