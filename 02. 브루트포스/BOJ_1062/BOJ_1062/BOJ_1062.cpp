

#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 50;
int N, K;

bool alpha[26] = {false};
int maxResult = 0;
string word[MAX];

bool check(int index) {
	for (int i = 0; i < word[index].length(); i++)
	{
		int wIdx = word[index][i]-'a';
		if (!alpha[wIdx]) {
			return false;
		}
	}
	return true;
}

void solve(int cnt,int alphaIndex) {
	if (cnt==K)
	{
		int result = 0;
		for (int i = 0; i < N; i++)
		{
			if (check(i))
			{
				result++;
			}
		}
		maxResult = max(result, maxResult);
		return;
	}
	for (int i = alphaIndex; i <26; i++)
	{
		if (!alpha[i]) {
			alpha[i] = true;
			solve(cnt + 1,i);
			alpha[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	if (K < 5)
	{
		cout << 0 << "\n";
		return 0;
	}

	//전부 익힐 수 있다
	else if (K == 26)
	{
		cout << N << "\n";
		return 0;
	}
	K -= 5;
	for (int i = 0; i < N; i++)
	{
		cin >> word[i];
		//anta
		word[i] = word[i].substr(4, word[i].length());
		//tica
		for (int j = 0; j < 4; j++)
			word[i].pop_back();
	}

	alpha['a' - 'a'] = true;
	alpha['c' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	solve(0,0);
	cout << maxResult;
}




