

#include <iostream>

using namespace std;

int N, M;

int uclid(int a, int b) {

	while (b!=0)
	{
		int num = a % b;
		a = b;
		b = num;
	}
	return a;
}

int main()
{
    cin >> N >> M;
	int gcd = uclid(N, M);
	cout << gcd << endl;
	cout << (N * M) / gcd << endl;
 }

