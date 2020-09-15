
#include <iostream>
#include <algorithm>
#include <string>

#define MAX 1001

using namespace std;

char A[MAX], B[MAX];
int DP[MAX][MAX];

int main()
{
	cin >> A >> B;
	int aSize = strlen(A);
	int bSize = strlen(B);

	for (int i = 1; i <= aSize; i++)
	{
		for (int j = 1; j <= bSize; j++)
		{
			if (A[i-1]==B[j-1])
			{
				DP[i][j] = DP[i - 1][j - 1]+1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}
	cout << DP[aSize][bSize];
}

