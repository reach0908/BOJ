// BOJ_10973.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<int> v(t);
	for (size_t i = 0; i < t; i++)
	{
		cin >> v[i];
	}

	if (prev_permutation(v.begin(), v.end()) == 0)
	{
		cout << -1;
		return 0;
	}

	for (size_t i = 0; i < t; i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}