// 최대공약수와 최소공배수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

//유클리드 호제법을 이용한 최대공약수 최소공배수

int gcd(int a, int b) {
	if (a<b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while (b!=0)
	{
		int n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
	int a, b;
	cin >> a >> b;
	int gcdNum = gcd(a, b);
	cout << gcdNum<< "\n" << (a * b) / gcdNum;
}

