
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int dp[1000];
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0;  j < i;  j++)
		{
			if (v[i]>v[j]&&dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	
//	10 20 10 30 20 50

//   1  2  1  3  2  4

	int maxN = 0;
	for (int i = 0; i < N; i++)
	{
		maxN = max(maxN, dp[i]);
	}
	cout << maxN;

	return 0;

}

