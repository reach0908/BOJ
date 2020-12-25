

#include <iostream>
#include <vector>


using namespace std;

const int MAX = 1001;

int N;

int A[MAX] = { 0 };
pair<int, vector<int>> cache[MAX];

void solve() {
	for (int i = 0; i < N; i++)
	{
		cache[i].first = 1;
		cache[i].second.push_back(A[i]);
		for (int j = 0; j < i; j++)
		{
			if (A[i]>A[j]&&cache[i].first<cache[j].first+1)
			{
				cache[i].first = cache[j].first+1;
				cache[i].second = cache[j].second;
				cache[i].second.push_back(A[i]);
			}
		}
	}
	int maxN = 0;
	int resIndex = 0;
	for (int i = 0; i < N; i++)
	{
		if (maxN<cache[i].first)
		{
			maxN = cache[i].first;
			resIndex = i;
		}
	}
	cout << cache[resIndex].first << endl;
	for (int i = 0; i < cache[resIndex].second.size(); i++)
	{
		cout << cache[resIndex].second[i] << " ";
	}

}
int main()
{

    cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	solve();
    return 0;
}

