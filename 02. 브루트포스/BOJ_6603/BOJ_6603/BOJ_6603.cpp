// BOJ_6603.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main()
{
	int n;
	int k=6;
	
	while (1)
	{
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		vector<int> tempVector;
		for (int i = 0; i < k; i++)
		{
			tempVector.push_back(0);
		}
		for (int i = 0; i < v.size() - k; i++)
		{
			tempVector.push_back(1);
		}
		sort(tempVector.begin(), tempVector.end());
		do
		{
			for (int i = 0; i < n; i++)
			{
				if (tempVector[i] == 0)
				{ // 실제값 출력
					cout << v[i] << " ";
				}
			}

			cout << endl;

		} while (next_permutation(tempVector.begin(), tempVector.end()));
		cout << endl;
	}
	return 0;
}

