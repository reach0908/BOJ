// BOJ_4150.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 피보나치 수

//피보나치 수 는 3가지 방법으로 풀 수 있다.

//1. 분할 정복
//2. 재귀
//3. 반복문

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string Add(string& s1, string& s2) {
	string result(max(s1.size(), s2.size()), 0);
	bool carry = false;

	for (int i = 0; i < result.size(); i++)
	{
		int temp = carry;
		carry = false;
		if (i < s1.size())
		{
			temp += s1[s1.size() - i - 1] - '0';
		}
		if (i < s2.size())
		{
			temp += s2[s2.size() - i - 1] - '0';
		}
		if (temp >= 10) {
			carry = true;
			temp -= 10;
		}
		result[result.size() - i - 1] = temp + '0';
	}
	if (carry)
	{
		result.insert(result.begin(), '1');
	}
	return result;
}


string fibo(int t) {
	string A, B, result;
	if (t == 0) {
		result = "0";
		return result;
	}
	if (t == 1) {
		result = "1";
		return result;
	}
	A = "0";
	B = "1";
	for (int i = 2; i <=t; i++)
	{
		result = Add(A, B);
		A = B;
		B = result;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int T;
	cin >> T;
	cout << fibo(T);
	return 0;
}
