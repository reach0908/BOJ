// BOJ_10819.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int compare(int a, int b) {
	return a > b ? a : b;
}

int main()
{
    int t;
    scanf_s("%d", &t);
	vector<int> v(t);
	
	int max = 0;
	for (int i = 0; i < t; i++)
	{
		scanf_s("%d", &v[i]);
	}
	sort(v.begin(),v.end());
	do {
		int sum = 0;
		for (int i = 0; i < t - 1; i++)
		{
				sum += abs(v[i] - v[i + 1]);
		}
		max = compare(max, sum);
	} while (next_permutation(v.begin(), v.end()));
	cout << max;
	return 0;
}

