// BOJ_10972.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



int N;

vector<int> v;



int main(void)

{

	cin >> N;



	v.resize(N);

	for (int i = 0; i < N; i++)

		cin >> v[i];



	int idx = N - 1;

	//v[idx - 1] < v[idx]를 만족하는 가장 큰 idx를 찾는다

	while (idx > 0 && v[idx - 1] >= v[idx])

		idx--;

	//마지막 순열

	if (idx == 0)
	{
		cout << -1 << "\n";
		return 0;
	}
	int idx2 = N - 1;
	//idx2 >= idx이면서 v[idx2] > v[idx2-1]을 만족하는 가장 큰 idx2를 찾는다
	while (v[idx - 1] >= v[idx2])
		idx2--;
	swap(v[idx - 1], v[idx2]);
	idx2 = N - 1;

	//v[idx]부터 순열을 뒤집는다

	while (idx < idx2)
	{
		swap(v[idx], v[idx2]);
		idx++;
		idx2--;
	}
	for (int i = 0; i < N; i++)
		cout << v[i] << " ";
	cout << "\n";
	return 0;
}





