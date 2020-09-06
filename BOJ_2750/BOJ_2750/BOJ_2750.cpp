// BOJ_2750.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
    int N;
    cin >> N;
    int* num = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N - i - 1; j++) {
            if (num[j]>num[j+1])
            {
                swap(num[j], num[j + 1]);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << num[i] << "\n";
    }
}

