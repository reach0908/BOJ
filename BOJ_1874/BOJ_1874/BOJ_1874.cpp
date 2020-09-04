// BOJ_1874.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
string result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int count = 1;
	for (int i = 0; i < N; i++)
	{
		int data;
		cin >> data;
		while (count <= data)
		{
			s.push(count);
			count++;
			result += '+';
		}
		if (s.top()==data)
		{
			s.pop();
			result += '-';
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}
	return 0;
}

