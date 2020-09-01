// BOJ_2920.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
// 문제 난이도 : 하
// 문제 유형 : 배열, 구현
// 추천 풀이 시간 : 15~30분
// 해결 시간 : 5분;

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

// 강의 문제풀이 해석
// 1. 리스트에서 원소를 차례 대로 비교합니다.
// 2. 비교할 때 두 원ㅅ고를 기준으로 오름차순/내림차순 여부를 체크한다.
// 해설은 오름차순과 내림차순을 bool값으로 둔다
// 둘다 false면 mixed 하나라도 true면 출력