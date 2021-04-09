
#include <iostream>
#include <string>

using namespace std;

int N;

int main()
{
	cin >> N;
	int cnt = 0;
	int startNum = 0;
	while (1)
	{
		startNum++;
		if (to_string(startNum).find("666") != string::npos) {
			cnt++;
		}
		if (cnt == N) {
			cout << startNum;
			break;
		}
	}
	return 0;
}

