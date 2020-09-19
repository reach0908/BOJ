
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
vector<char> password;
vector<int> comb;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> L >> C;
	password.resize(C);
	for (int i = 0; i < C; i++)
	{
		cin >> password[i];
	}
	for (int i = 0; i < L; i++)
	{
		comb.push_back(0);
	}
	for (int i = 0; i < C-L; i++)
	{
		comb.push_back(1);
	}
	sort(password.begin(), password.end());

	do
	{
		string result;
		bool iscontatin = false;
		int count = 0;
		for (int i = 0; i < C; i++)
		{
			if (comb[i] == 0) {
				if (password[i]=='a'|| password[i] == 'e'|| password[i] == 'i'|| password[i] == 'o'|| password[i] == 'u')
				{
					iscontatin = true;
					result += password[i];
				}
				else {
					count++;
					result += password[i];
				}
			}
		}
		if (iscontatin&&count>1) {
			cout << result << "\n";
		}

	} while (next_permutation(comb.begin(),comb.end()));
	return 0;
}
