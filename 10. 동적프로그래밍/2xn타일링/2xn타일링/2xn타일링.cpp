

#include <iostream>

using namespace std;

const int MAX = 1001;

int rect[MAX] = { 0 };

int N;

int main()
{
    cin >> N;
	rect[1] = 1;
	rect[2] = 2;
	for (int i = 3; i <=N; i++)
	{
		rect[i] = (rect[i - 1] + rect[i - 2]) % 10007;
	}
	cout << rect[N]%10007;
	return 0;
}

