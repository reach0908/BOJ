

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstring>
const int MAX=4000000;

using namespace std;

int N;
long long minFactor[MAX];
vector<int> prime;
//에라토스테네스의 체를 이용해 소수들 벡터에 저장후
// 그를 이용한 부분합 구하기 및 카운트

void erathos() {
	minFactor[0] = minFactor[1] = -1;

	for (long long i = 2; i < MAX; i++)

		minFactor[i] = i;



	for (long long i = 2; i < MAX; i++)

		if (minFactor[i] == i)

			for (long long j = i * i; j < MAX; j += i)

				if (minFactor[j] == j)

					minFactor[j] = i;



	for (int i = 2; i < MAX; i++)

		if (minFactor[i] == i)

			prime.push_back(i);
}

void solve() {
	erathos();
	int cnt = 0;
	int low = 0, high = 0;
	int sum = prime[0];

	while (low<=high&&high<prime.size()&&prime[low]<=N)
	{
		if (sum < N) {
			sum += prime[++high];
		}
		else if (sum == N) {
			cnt++;
			sum += prime[++high];
		}
		else if (sum > N) {
			sum -= prime[low++];
			if (low > high && low < prime.size()) {
				high = low;
				sum = prime[low];
			}
		}
	}

	cout << cnt;
}

int main()
{
	cin >> N;
	solve();
	return 0;
}

