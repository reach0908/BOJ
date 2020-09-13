// 나머지.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A + B) % C << "\n" << ((A % C) + (B % C)) % C << "\n" << (A*B) % C << "\n" << ((A % C) *(B % C)) % C;
    return 0;
}
