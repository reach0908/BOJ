// BOJ_1302.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<string, int>> v;

int main()
{
	int T;
	cin >> T;
	v.resize(T);

	for (int i = 0; i < T; i++)
	{
		v[i].second = 0;
	}
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		bool found = false;
		for (int j = 0; j < i; j++)
		{
			if (s == v[j].first) {
				v[j].second++;
				found = true;
				break;
			}
		}
		if (found)
		{
			continue;
		}
		else {
			v[i].first = s;
			v[i].second++;
		}
	}
	int max = 0;
	for (int i = 0; i < T; i++)
	{
		if (max<v[i].second)
		{
			max = v[i].second;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < T; i++)
	{
		if (max==v[i].second)
		{
			cout << v[i].first << endl;
			return 0;
		}
	}
}

