// 가장긴감소하는부분수열.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int A[MAX];
long long cache[MAX];

int N;

long long solve() {
    long long result=0;
    
    for (int i = 0; i < N; i++)
    {
        cache[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i]<A[j]&&cache[j]+1>cache[i])
            {
                cache[i] = cache[j] + 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        result = max(result, cache[i]);
    }


    return result;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << solve();
    return 0;
}

