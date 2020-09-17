//
//  main.cpp
//  등수 매기기
//
//  Created by KJH on 2020/09/17.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> predict;

int main() {
    
    cin >>N;
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        predict.push_back(temp);
    }
    sort(predict.begin(), predict.end());
   long long result = 0;
    for (int i=1; i<=N; i++) {
        result += abs(i-predict[i-1]);
    }
    cout << result;
    return 0;
}
