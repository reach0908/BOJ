
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 11;

int N;
char S[MAX][MAX];
pair<char, int> num[MAX];
bool found = false;

bool check(int a) {

	for (int i = a; i < N; i++)
	{
		int temp = 0;
		if (S[a][i] == '0') {
			for (int j = a; j <= i; j++)
			{
				temp += num[j].second;
			}
			if (temp != 0) {
				return false;
			}
		}
		else if (S[a][i] == '+') {
			for (int j = a; j <= i; j++)
			{
				temp += num[j].second;
			}
			if (temp <= 0) {
				return false;
			}
		}
		else {
			for (int j = a; j <= i; j++)
			{
				temp += num[j].second;
			}
			if (temp >= 0) {
				return false;
			}
		}
	}
	return true;
}

void solve(int start) {
	if (start < 0 && !found) {
		for (int i = 0; i < N; i++)
		{
			cout << num[i].second << " ";
		}
		found = true;
		return;
	}
	for (int j = 0; j < MAX; j++)
	{

		if (num[start].first == '+')
		{
			num[start].second = 1 * j;
		}
		else {
			num[start].second = -1 * j;
		}
		if (check(start))
		{
			solve(start - 1);
			if (found)
			{
				return;
			}
		}
	}
}

int main()
{
	cin >> N;
	string stemp;
	cin >> stemp;
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			S[i][j] = stemp[index];
			if (i == j) {
				num[i].first = stemp[index];
			}
			index++;
		}
	}
	solve(N - 1);
}
