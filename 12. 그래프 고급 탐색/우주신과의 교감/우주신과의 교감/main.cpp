//
//  main.cpp
//  우주신과의 교감
//
//  Created by KJH on 2020/09/17.
//  Copyright © 2020 KJH. All rights reserved.
//

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
 
#define endl "\n"
#define MAX 1010
using namespace std;
 
int N, M;
int Parent[MAX];
double Answer;
vector<pair<int, int>> Coord;
vector<pair<int, int>> Connect;
vector<pair<double, pair<int, int>>> Edge;
 
void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) Parent[i] = i;
    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        Coord.push_back(make_pair(a, b));
    }
    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        Connect.push_back(make_pair(a, b));
    }
}
 
int Find_Parent(int A)
{
    if (A == Parent[A]) return A;
    return Parent[A] = Find_Parent(Parent[A]);
}
 
bool Same_Parent(int A, int B)
{
    A = Find_Parent(A);
    B = Find_Parent(B);
    if (A == B) return true;
    return false;
}
 
void Union(int A, int B)
{
    A = Find_Parent(A);
    B = Find_Parent(B);
    Parent[B] = A;
}
 
double Find_Distance(int x, int y, int xx, int yy)
{
    double dx = pow(x - xx, 2);
    double dy = pow(y - yy, 2);
    double Dist = sqrt(dx + dy);
 
    return Dist;
}
 
void Solution()
{
    for (int i = 0; i < M; i++)
    {
        int N1 = Connect[i].first;
        int N2 = Connect[i].second;
 
        if (Same_Parent(N1, N2) == false) Union(N1, N2);
    }
    for (int i = 0; i < N - 1; i++)
    {
        int x = Coord[i].first;
        int y = Coord[i].second;
        for (int j = i + 1; j < N; j++)
        {
            int xx = Coord[j].first;
            int yy = Coord[j].second;
 
            double Dist = Find_Distance(x, y, xx, yy);
            Edge.push_back(make_pair(Dist, make_pair(i + 1, j + 1)));
        }
    }
    sort(Edge.begin(), Edge.end());
    for (int i = 0; i < Edge.size(); i++)
    {
        int N1 = Edge[i].second.first;
        int N2 = Edge[i].second.second;
        double Dist = Edge[i].first;
 
        if (Same_Parent(N1, N2) == false)
        {
            Union(N1, N2);
            Answer = Answer + Dist;
        }
    }
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //소수점 출력 고정하기
    cout << fixed;
    cout.precision(2);
 
    Solve();
 
    return 0;
}
