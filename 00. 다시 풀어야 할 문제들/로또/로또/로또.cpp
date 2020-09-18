
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		int N;
		cin >> N;
		if (N==0)
		{
			break;
		}
		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		vector<int> check;
		for (int i = 0; i < 6; i++)
		{
			check.push_back(0);
		}
		for (int i = 0; i < N-6; i++)
		{
			check.push_back(1);
		}
		do
		{
			for (int i = 0; i < N; i++)
			{
				if (check[i]==0)
				{
					cout << v[i] << " ";
				}
			}
			cout << "\n";
		} while (next_permutation(check.begin(),check.end()));
		cout << "\n";
	}
	return 0;
}
