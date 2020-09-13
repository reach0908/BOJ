// BOJ_10974.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf_s("%d", &t);
	vector<int> v(t);
	for (size_t i = 0; i < t; i++)
	{
		v[i] = i + 1;
	}

	do {
		for (size_t i = 0; i < t; i++)
		{
			printf("%d ", v[i]);
		}
		puts("");
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}