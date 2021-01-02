

#include <iostream>

using namespace std;

const int MAX = 16;

int N;
int result=0;

int col[MAX] = { 0 };

bool check(int level) {
	for (int i = 0; i < level; i++)
	{
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) {
			return false;
		}
	}
	return true;
}


void nqueen(int x) {
	if (x == N) {
		result++;
	}
	else {
		for (int i = 0; i < N; i++)
		{
			col[x] = i;
			if (check(x))
			{
				nqueen(x + 1);
			}
		}
	}
}
int main()
{
    cin >> N;
	nqueen(0);
	cout << result;
}
