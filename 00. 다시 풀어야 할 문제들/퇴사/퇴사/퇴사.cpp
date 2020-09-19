

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DAY;

vector<pair<int, int>> v;

int MAX = 0;

void func(int start, int value) {
	if (start>DAY)
	{
		return;
	}
	if (start + v[start].first <= DAY+1) {
		MAX = max(MAX, value + v[start].second);
	}
	func(start + 1, value);
	func(start + v[start].first, value + v[start].second);
}// 소요되는 날짜,가치

int main()
{
	cin >> DAY;
	v.resize(DAY+1);
	v[0].first = 1;
	v[0].second = 0;
	for (int i = 1; i <= DAY; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	func(0, 0);
	cout << MAX;
}

