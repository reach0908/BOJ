


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<long long> v;
long long L = 1;
long long R = 0;
long long result = 0;
long long isMatch(long long n) {
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i] - n>0) {
			sum += v[i] - n;
		}
	}
	if (sum >= M) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		R = max(R, temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	while (L <= R)
	{
		long long mid = (L + R) / 2;
		if (isMatch(mid)) {
			result = max(result, mid);
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	cout << result << endl;
	return 0;
}