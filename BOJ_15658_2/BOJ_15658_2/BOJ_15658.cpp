//
//  main.cpp
//  BOJ_15658_2
//
//  Created by KJH on 2020/09/04.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 999999999

using namespace std;

int T;
int p,mi,mul,d;

vector<int> operV;
vector<int> num;
vector<bool> operB;
int MIN=INF;
int MAX=-INF;

void func(vector<int> chooseV){
   
    do{
        int result=num[0];
        int index=1;
        for (int i=0; i<chooseV.size(); i++) {
             
                 if (chooseV[i]==0) {
                     result=result+num[index];
                     index++;
                 }
                 if (chooseV[i]==1) {
                   result=result-num[index];
                   index++;
                 }
                 if (chooseV[i]==2) {
                     result=result*num[index];
                     index++;
                 }
                 if (chooseV[i]==3) {
                     result=result/num[index];
                     index++;
                 }
         }
        MAX = max(MAX, result);
        MIN = min(MIN,result);
    }while (next_permutation(chooseV.begin(), chooseV.end()));
}
void choose(){
    vector<int> chooseV;
    for (int i=0; i<operV.size(); i++) {
        if (operB[i]) {
            if (operV[i]==0) {
                chooseV.push_back(0);
            }
            if (operV[i]==1) {
              chooseV.push_back(1);
            }
            if (operV[i]==2) {
                chooseV.push_back(2);
            }
            if (operV[i]==3) {
                chooseV.push_back(3);
            }
        }
    }
    func(chooseV);
}
void DFS(int Idx, int Cnt)
{
    if (Cnt == T-1)
    {
        choose();
        return;
    }
 
    for (int i = Idx; i < operV.size(); i++)
    {
        if (operB[i] == true) continue;
        operB[i] = true;

        DFS(i, Cnt + 1);
        operB[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>T;
    
    for (int i=0; i<T; i++) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    cin >> p >> mi >> mul>>d;
    for (int i=0; i<p; i++) {
        operV.push_back(0);
        operB.push_back(false);
    }
    for (int i=0; i<mi; i++) {
        operV.push_back(1);
        operB.push_back(false);
    }
    for (int i=0; i<mul; i++) {
        operV.push_back(2);
        operB.push_back(false);
    }
    for (int i=0; i<d; i++) {
        operV.push_back(3);
        operB.push_back(false);
    }
    
    DFS(0, 0);
    cout << MAX<<endl;
    cout << MIN<<endl;
    return 0;
}
