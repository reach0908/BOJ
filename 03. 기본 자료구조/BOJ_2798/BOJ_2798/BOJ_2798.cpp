// BOJ_2798.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 문제 제목 : 블랙잭
// 문제 난이도 : 하
// 문제 유형  : 배열, 완전탐색
// 추천 풀이 시간 : 20분


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int BJ;


int main()
{
	cin >> T >> BJ;
	vector<int> v(T);
	for (int i = 0; i < T; i++)
	{
		cin >> v[i];
	}
	int result = 0;
	int sum = 0;
	for (int i = 0; i < T; i++)
	{
		for (int j = i+1; j <T; j++)
		{
			for (int k = j + 1; k < T; k++) {
				sum = v[i] + v[j] + v[k];
				if (sum<=BJ)
				{
					result = max(result, sum);
				}
			}
		}
	}
	cout << result;
}

//문제 풀이 핵심 아이디어
//최악의 경우에도 연산개수가 많지 않기에 완점탐색을 해도 된다.

