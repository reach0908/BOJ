// BOJ_10989.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#define MAX_SIZE 10001

//10000개 까지면 배열은 10001을 잡아주어야 한다.
using namespace std;

int T;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	v.resize(MAX_SIZE);
	v.assign(MAX_SIZE,0);

	for (int i = 0; i < T; i++)
	{
		int temp;
		cin >> temp;
		v[temp]++;
	}
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (v[i]!=0) {
			for (int j = 0; j < v[i]; j++)
			{
				cout << i << "\n";
			}
		}
	}
	return 0;
}


//첫 시도 - 메모리 초과

// 수의 양은 많지만 수의 범위가 좁을 때 사용할 수 있는 알고리즘
// 계수 정렬 이용 (counting sort)

