// BOJ_10539.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
const int MAX = 101;
int N;
int A[MAX];
int B[MAX];
int aSUM[MAX];

int DP(int n) {
	if (n==1)
	{
		A[1] = B[1];
		aSUM[1] = B[1];
	}
	return A[n] = (B[n] * n) - aSUM[n - 1];
}


int main()
{
    cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> B[i];
	}
	for (int i = 1; i <=N ; i++)
	{
		A[i] = DP(i);
		aSUM[i] = aSUM[i - 1] + A[i];
		cout << A[i] << " ";
	}
}
