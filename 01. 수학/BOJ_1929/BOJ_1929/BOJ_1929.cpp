

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAX = 1000000;
bool arr[MAX + 1];
int M, N;

void eratosthenes(int min, int max) {
	arr[0] = false;
	arr[1] = false;
	for (int i = 2; i <=sqrt(N); i++)
	{
		if (arr[i]) {
			for (int j = i * 2; j <= N; j += i) {
				arr[j] = false;
			}
		}
	}
	for (int i = M; i <= N; i++)
	{
		if (arr[i]) {
			cout << i << "\n";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(arr, true,sizeof(arr));
	cin >> M >> N;
	eratosthenes(M,N);
	return 0;
}
