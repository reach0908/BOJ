
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		v.push_back(i);
	}

	do
	{
		for (int i = 0; i < T; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(),v.end()));
	return 0;
}

