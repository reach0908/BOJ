

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<int> v;

int binsearch(int start,int end,int target) {
	if (start>end)
	{
		return 0;
	}
	else {
		int mid = (start + end) / 2;
		if (v[mid] == target)
		{
			
			return 1;
		}
		else if (v[mid] < target) {
			return binsearch(mid + 1, end, target);
		}
		else {
			return binsearch(start, mid - 1, target);
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
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		cout << binsearch(0, N - 1, temp) << "\n";
	}
	return 0;
}

