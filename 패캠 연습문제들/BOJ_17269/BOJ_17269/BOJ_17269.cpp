// BOJ_17269.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string A, B;
vector<int> v;

int arr[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };

void merge(int n,int m) {
	int aIndex;
	int bIndex;
	while (n<N&&m<M)
	{
		aIndex = A[n] - 'A';
		bIndex = B[m] - 'A';
		v.push_back(arr[aIndex]);
		n++;
		v.push_back(arr[bIndex]);
		m++;
	}
	if (n<N)
	{
		for (int i = n; i < N; i++)
		{
			aIndex = A[i] - 'A';
			v.push_back(arr[aIndex]);
		}
	}
	else if (m<M)
	{
		for (int i = m; i < M; i++)
		{
			bIndex = B[i] - 'A';
			v.push_back(arr[bIndex]);
		}
	}
	while (v.size()>2)
	{
		for (int i = 0; i < v.size() - 1; i++)
		{
			int temp = v[i] + v[i + 1];
			v[i] = temp % 10;
		}
		v.pop_back();
	}
	if (v[0]!=0)
	{
		cout << v[0] << v[1] << "%";
	}
	else {
		cout << v[1] << "%";
	}
}


int main()
{
    cin >> N >> M;
	cin >> A >> B;
	merge(0, 0);
}

