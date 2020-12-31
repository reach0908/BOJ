
#include <iostream>
#include<string>
#include<math.h>

using namespace std;
string N;
int main()
{
	cin >> N;
	long ans=0;
	int len = N.length();
	if (len == 1) {
		cout << N;
		return 0;
	}
	for (int i = 1; i < len; i++)
	{
		ans += i * (9 * pow(10, i - 1));
	}
	ans += len * (stoi(N) - pow(10, len - 1) + 1);
	cout << ans;
}


