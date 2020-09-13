// BOJ_10920.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int binarySearch(int low, int high, int target) {
	if (low>high)
	{
		return 0;
	}
	else
	{
		int mid = (low + high) / 2;
		if (v[mid]==target)
		{
			return 1;
		}
		else if (v[mid]>target)
		{
			return binarySearch(low, mid - 1, target);
		}
		else
		{
			return binarySearch(mid + 1, high, target);
		}
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		cout << binarySearch(0, N - 1, num) << "\n";
	}
	return 0;
}

