

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100001;
int N, K;

int v[MAX] = { 0 };
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v, v + N);
	vector<int> diff(N - 1);
	for (int i = 0; i < N - 1; i++)
	{
		diff[i] = v[i + 1] - v[i];
	}
	sort(diff.begin(), diff.end());
	int result = 0;
	for (int i = 0; i < N - K; i++)
	{
		result += diff[i];
	}
	cout << result << "\n";
	return 0;


}

