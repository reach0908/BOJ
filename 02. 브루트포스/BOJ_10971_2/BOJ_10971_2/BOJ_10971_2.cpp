
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int node[10][10];

int main()
{
    int T;
    cin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++) {
			cin >> node[i][j];
		}
	}
	int result= 2147483647;
	vector<int> v(T+1);
	for (int i = 0; i <= T; i++)
	{
		v[i] = i;
	}
	do {
		bool flag = true;
		int sum = 0;
		v[T] = v[0];
		for (int i = 0; i < T; i++)
		{
			if (node[v[i]][v[i + 1]] == 0) {
				flag = false;
				break;
			}
			else
			{
				sum += node[v[i]][v[i + 1]];
			}
		}
		if (flag) {
			result = min(result, sum);
		}
	} while (next_permutation(v.begin(), v.end()-1));
	
	cout << result;
}

