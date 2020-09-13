// 소수찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <math.h>


using namespace std;

bool eratos(int n) {
    if (n==1)
    {
        return false;
    }
    int k = (int)sqrt(n);
    for (int i = 2; i <= k; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i <n ; i++)
    {
        int temp;
        cin >> temp;
        if (eratos(temp))
        {
            count++;
        }
    }
    cout << count;
}
