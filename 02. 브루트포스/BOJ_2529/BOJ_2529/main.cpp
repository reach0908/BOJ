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
const int MAX = 10;

using namespace std;

int K;

string ansMIN = "999999999";
string ansMAX = "0";

vector<char> b;
bool visited[MAX] = {false};

void solve(int numIndex,int bIndex, string num){
    if(numIndex>K-1&&bIndex>K-1){
        if(stoi(ansMIN)>stoi(num)){
            ansMIN=num;
        }
        if(stoi(ansMAX)<stoi(num)){
            ansMAX = num;
        }
        return;
    }
    
    for (int i=0; i<MAX; i++) {
        if(num==""){
            visited[i] = true;
            solve(numIndex, bIndex, num+to_string(i));
            visited[i]=false;
        }else{
            if(!visited[i]){
                if (b[bIndex]=='>') {
                    if (num[numIndex]-'0'>i) {
                        visited[i] = true;
                        solve(numIndex+1, bIndex+1, num+to_string(i));
                        visited[i]=false;
                    }
                }else{
                    if (num[numIndex]-'0'<i) {
                        visited[i] = true;
                        solve(numIndex+1, bIndex+1, num+to_string(i));
                        visited[i]=false;
                    }
                }
            }
        }
    }
    
    
}

int main() {
    cin >> K;
    for (int i=0; i<K; i++) {
        char temp;
        cin >> temp;
        b.push_back(temp);
    }
    solve(0,0,"");
    cout << ansMAX << endl;
    cout << ansMIN << endl;
    return 0;
}
