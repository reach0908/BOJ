#include <iostream>

using namespace std;

const int MAX = 1001;

int N;

int cache[MAX] = { 0 };


int main() {
	cin >> N;
	cache[1] = 1;
	cache[2] = 3;
	for (int i = 3; i <=N; i++)
	{
		cache[i] = (cache[i - 1] + (cache[i - 2] * 2)) % 10007;
	}
	cout << cache[N];
	return 0;
}