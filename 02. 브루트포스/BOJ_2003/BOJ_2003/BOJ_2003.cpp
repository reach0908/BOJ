

#include <iostream>

using namespace std;

const int MAX = 10000;

int N, M;
int A[MAX];
int cnt=0;

int main()
{
    cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		int sum = A[i];
		if (sum == M) {
			cnt++;
		}
		for (int j = i+1; j < N; j++)
		{
			sum += A[j];
			if (sum == M) {
				cnt++;
			}
		}
	}
	cout << cnt;
}

