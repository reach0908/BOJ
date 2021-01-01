

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<string> word;
int alphabet[26] = {0};
int N;

bool comp(int a, int b) {
	return a > b;
}

void solve() {
	sort(alphabet, alphabet+26,comp);
	int temp = 9;
	int total = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] != 0) {
			total += temp * alphabet[i];
			temp--;
		}
	}
	cout << total;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		word.push_back(temp);
	}
	
	for (int i = 0; i < word.size(); i++)
	{
		for (int j = 0; j < word[i].length(); j++)
		{
			alphabet[word[i][j] - 'A'] += pow(10, word[i].length() - (j+1));
		}
	}
	solve();

	return 0;
}

