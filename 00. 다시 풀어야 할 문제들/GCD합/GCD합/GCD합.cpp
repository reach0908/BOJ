

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (a<b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while (b!=0)
	{
		int n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
    int t;
    cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++)
		{
			cin >> v[j];
		}
		int result = 0;
		for (int j= 0; j < n;j++)
		{
			for (int k = j+1; k < n; k++)
			{
				result += gcd(v[j], v[k]);
			}
		}
		cout << result << "\n";
	}
}

