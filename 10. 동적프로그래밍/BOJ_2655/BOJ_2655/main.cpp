//
//  main.cpp
//  BOJ_2655
//
//  Created by KJH on 2020/09/15.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Block{
    int weight;
    int size;
    int height;
    int num;
};

bool comp(const Block&a,const Block &b){
    return a.weight<b.weight;
}

int N;

int dp[101]={0};
vector<int> num;

Block block[101]={0};

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> block[i].size >> block[i].height >> block[i].weight;
        block[i].num = i;
    }
    sort(block, block+N+1,comp);
    for (int i=1; i<=N ; i++) {
        dp[i] = block[i].height;
        for (int j=0; j<i; j++) {
            if (block[j].size<block[i].size) {
                dp[i]=max(dp[i],dp[j]+block[i].height);
            }
        }
    }
    int maxNum =0;
    for (int i=0; i<=N; i++) {
        maxNum = max(maxNum,dp[i]);
    }
    int index =N;
    vector<int> result;
    while (index!=0) {
        if (maxNum == dp[index]) {
            result.push_back(block[index].num);
            maxNum -= block[index].height;
        }
        index--;
    }
    cout<<result.size()<<endl;
    int top =(int)result.size();
    for (int i=top-1; i>=0; i--) {
        cout << result[i]<<endl;
    }
    return 0;
}
