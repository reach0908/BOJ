
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
const int MAX = 1001;

using namespace std;

bool arr[MAX];

int N;
vector<int> v;

void eratosthenes() {
	memset(arr, true, sizeof(arr));
	arr[0] = false;
	arr[1] = false;
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (arr[i]) {
			for (int j = i * 2; j < MAX; j += i)
			{
				arr[j] = false;
			}
		}
	}
}

int main()
{
    cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	eratosthenes();
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[v[i]]) {
			cnt++;
		}
	}
	cout << cnt << endl;
}

