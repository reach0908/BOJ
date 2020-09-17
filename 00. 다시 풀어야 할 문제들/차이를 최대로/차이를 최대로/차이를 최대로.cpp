// 차이를 최대로.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    vector<int> v(T);
    for (int i = 0; i < T; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int maxN=0;
    do
    {
        int sum = 0;
        for (int i = 0; i < T-1; i++)
        {
            sum += abs(v[i] - v[i + 1]);
        }
        maxN = max(maxN, sum);
    } while (next_permutation(v.begin(),v.end()));

    cout << maxN;
    return 0;
}
