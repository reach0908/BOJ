

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> arr;
int N, M;
int res = -1;

int main()
{
    cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < N-3; i++)
	{
		v.push_back(0);
	}for (int i = 0; i < 3; i++)
	{
		v.push_back(1);
	}
	do
	{
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (v[i] == 1) {
				sum += arr[i];
			}
		}
		if (sum <= M) {
			res = max(res, sum);
		}
	} while (next_permutation(v.begin(),v.end()));
	cout << res;
}

