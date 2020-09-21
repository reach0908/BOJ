// 평범한배낭.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//knapsack 알고리즘 이용
// 1. i번째 물건을 가져갈 때 : D[i][j] = D[i-1][j-w[i]] + v[i] 라고 할수 있다
// 2. i번째 물건을 안가져갈 때 :  D[i][j] = D[i-1][j]가 된다.
// i를 첫번째 보석부터 n번째 보석까지
//j를 0kg에서 k(배낭에 담을 수 있는 무게)까지
// D[i][j] = max(D[i][j],D[i-1][j-w[i]]+v[i])

int d[102][100002];


int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> wv;
    wv.push_back(make_pair(0, 0));
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        wv.push_back(make_pair(a, b));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            d[i][j] = d[i - 1][j];
            if (j>=wv[i].first)
            {
                d[i][j] = max(d[i][j], d[i - 1][j - wv[i].first] + wv[i].second);
            }
        }
    }
    cout << d[n][k];
}
