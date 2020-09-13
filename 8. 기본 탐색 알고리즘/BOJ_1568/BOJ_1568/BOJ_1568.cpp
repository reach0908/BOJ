// BOJ_1568.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int index=1;
    int num=0;
    while (t!=0)
    {
        if (index>t)
        {
            index = 1;
            continue;
        }
        else {
            t -= index;
            index++;
            num++;
        }
    }
    cout << num;
}

