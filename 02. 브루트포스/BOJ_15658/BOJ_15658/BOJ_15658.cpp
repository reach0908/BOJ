//
//  main.cpp
//  BOJ_15658
//
//  Created by KJH on 2020/08/29.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999

using namespace std;

int compareMin(int a, int b) {
    return a > b ? b : a;
}
int compareMax(int a, int b) {
    return a > b ? a : b;
}

int minNum=INF;
int maxNum = -INF;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int plus,minus,mul,div;
    cin >> plus >> minus >> mul >> div;

    vector<char> operV;

    int i, j, k, l;

    for (i=0; i < plus; i++)
    {
        operV.push_back('a');
    }
    for (j=i; j < i+minus; j++)
    {
        operV.push_back('b');
    }
    for (k=j; k < j+mul; k++)
    {
       operV.push_back('c');
    }
    for (l=k;l<k+div; l++)
    {
        operV.push_back('d');
    }

    vector<int> temp;

    for (int i=0; i<N-1; i++) {
        temp.push_back(0);
    }
    for (int i=0; i<N-1-temp.size(); i++) {
        temp.push_back(1);
    }
    do
    {
        int count = 0;
        int sum = v[0];
        while (count < temp.size())
        {
            if (temp[count]==1) {
                count++;
                break;
            }
            char operTmp = operV[count];
            switch (operTmp)
            {
            case 'a':
                sum = sum + v[count+1];
                break;
            case 'b':
                sum = sum - v[count+1];
                break;
            case 'c':
                sum = sum * v[count+1];
                break;
            case 'd':
                sum = sum / v[count + 1];
                break;
            }
            count++;
        }
        maxNum = compareMax(maxNum, sum);
        minNum = compareMin(minNum, sum);
    } while (next_permutation(temp.begin(), temp.end()));

    cout << maxNum << endl;
    cout << minNum << endl;

    return 0;
}
