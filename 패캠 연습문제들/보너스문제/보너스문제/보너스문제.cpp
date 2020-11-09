

#include <iostream>
#include <string>

using namespace std;

const int MAX = 10000;

int cache[MAX] = { 0 };

int N;
string s;

int solve() {
	int curBonus=0;
	int score = 0;
	for (int i = 0; i < N; i++)
	{
		if (s[i]=='X')
		{
			curBonus = 0;
			continue;
		}
		else {
			score += (i+ 1 + curBonus);
			curBonus++;
		}
		
	}
	return score;
}

int main()
{
    cin >> N;
    cin >> s;
	cout << solve();
	return 0;

}

