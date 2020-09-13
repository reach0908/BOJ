
#include <iostream>


using namespace std;

int gcd(int a, int b) {
	if (a<b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) {
		int n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << (a * b) / gcd(a, b) << "\n";
	}
	return 0;

}

