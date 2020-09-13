// 크루스칼알고리즘 시 배운
// 유니온 파인드를 이용  -- 합집합 문제에서 활용가능
// c++에서 해쉬로 풀어야 한다면- 맵 라이브러리를 이용
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100000 + 1;

int F;
int parent[MAX], setSize[MAX];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (setSize[a]<setSize[b])
	{
		parent[a] = b;
		setSize[b] += setSize[a];
		setSize[a] = setSize[b];
	}
	else
	{
		parent[b] = a;
		setSize[a] += setSize[b];
		setSize[b] = setSize[a];
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++)
	{
		cin >> F;
		for (int i = 0; i < MAX; i++)
		{
			parent[i] = i;
			setSize[i] = 1;
		}
		map<string, int> name;
		int index = 1;
		for (int i = 0; i < F; i++)
		{
			string temp1, temp2;
			cin >> temp1 >> temp2;

			if (name.count(temp1)==0)
			{
				name[temp1] = index++;
			}
			if (name.count(temp2) == 0)
			{
				name[temp2] = index++;
			}

			int temp1Parent = getParent(name[temp1]);
			int temp2Parent = getParent(name[temp2]);
			if (temp1Parent == temp2Parent) {
				cout << max(setSize[temp1Parent], setSize[temp2Parent]) << "\n";
			}
			else
			{
				unionParent(temp1Parent, temp2Parent);
				cout << max(setSize[temp1Parent], setSize[temp2Parent]) << "\n";
			}

		}
	}

	return 0;

}