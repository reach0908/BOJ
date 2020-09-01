// BOJ_2920.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// 문제 난이도 : 하
// 문제 유형 : 배열, 구현
// 추천 풀이 시간 : 15~30분


#include <iostream>
#include <vector>

using namespace std;

vector<int> v(8);

int main()
{
	int desc = 0;
	int asce = 0;
	for (int i = 0; i < 8; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < 7; i++)
	{
		if (v[i] < v[i + 1]) {
			asce++;
		}
		else { desc++; }
	}
	if (asce == 7) {
		cout << "ascending";
	}
	else if (desc == 7) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}
	return 0;
}

