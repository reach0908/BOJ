
#include <iostream>
#include <vector>
using namespace std;

int N,S;
vector<int> num;
int result;
void func(int start,int end,int sum) {
	for (int i = start; i < end; i++)
	{
		sum += num[i];
	}
	if (sum==S)
	{
		result++;
	}
}

int main()
{
    cin >> N >> S;
	num.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i; j < N; j++)
		{
			func(i, j, 0);
		}
	}
	cout << result;
}

