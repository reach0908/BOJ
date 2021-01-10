

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 4000;
int n;

int arr[4][MAX];
vector<int> l;
vector<int> r;
long long ans=0;
int main()
{
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arr[j][i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j= 0; j < n; j++)
		{
			l.push_back(arr[0][i] + arr[1][j]);
			r.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	for (int i = 0; i < l.size(); i++)
	{
		long long low = lower_bound(r.begin(), r.end(), 0 - l[i]) - r.begin();
		long long high = upper_bound(r.begin(), r.end(), 0 - l[i]) - r.begin();

		ans += high - low;
	}
	cout << ans;
}

