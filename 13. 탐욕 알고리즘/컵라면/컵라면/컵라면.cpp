
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;
vector<pair<int, int>> ramen;
int main()
{
    cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		ramen.push_back(make_pair(a, b));
	}
	stable_sort(ramen.begin(), ramen.end());
	
	for (int i = 0; i < N; i++)
	{
		pq.push(ramen[i].second);
		if (pq.size()>ramen[i].first)
		{
			pq.pop();
		}
	}
	int result = 0;
	while (!pq.empty())
	{
		int temp = pq.top();
		pq.pop();
		result += temp;
	}
	cout << result;
	return 0;
}

