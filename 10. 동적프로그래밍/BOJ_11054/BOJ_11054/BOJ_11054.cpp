

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int A[MAX];
int cacheP[MAX];
int cacheM[MAX];

int N;

void solve() {
	for (int i = 0; i < N; i++)
	{
		cacheP[i] = 1;
		
		for (int j = 0; j < i; j++)
		{
			if (A[i]>A[j]&&cacheP[i]<cacheP[j]+1)
			{
				cacheP[i] = cacheP[j] + 1;
			}
		}
		
	}
	
	for (int i = N-1; i >=0; i--)
	{
		cacheM[i] = 1;
		for (int j = N - 1; j >i; j--)
		{
			if (A[i] > A[j] && cacheM[i] < cacheM[j] + 1)
			{
				cacheM[i] = cacheM[j] + 1;
			}
		}
		
	}

	int res = 0;
	for (int i = 0; i < N; i++)
	{
		res = max(res, cacheP[i]+cacheM[i]-1);
	}
	cout << res;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	solve();
}
