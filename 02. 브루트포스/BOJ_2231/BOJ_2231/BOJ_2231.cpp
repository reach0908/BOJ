
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int N,M;
const int MAX = 1000001;
int result = 1e9;
int solve(int num) {
	int sum = 0;
	string temp = to_string(num);

	for (int i = 0; i < temp.size(); i++)
	{
		sum += temp[i] - '0';
	}
	return sum+num;
}


int main()
{
    cin >> N;
	bool isExist=false;
	for (int i = 1; i <= N; i++)
	{
		int ret = solve(i);
		if (ret == N) {
			result = min(i, result);
			isExist = true;
		}
	}
	if (isExist) {
		cout << result;
	}
	else {
		cout << 0;
	}
	return 0;
}

