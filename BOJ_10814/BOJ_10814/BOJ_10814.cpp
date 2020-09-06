﻿// BOJ_10814.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, string>> v;



bool cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        return false;
    return false;

}

void printMember(void)
{
    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << "\n";

}



int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상 위해
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    printMember();
    return 0;
}


