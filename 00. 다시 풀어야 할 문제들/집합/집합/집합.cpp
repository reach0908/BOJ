
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
bool arr[21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
	fill(arr, arr + 21, false);
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		
		if (s=="add")
		{
			int index;
			cin >> index;
			arr[index] = true;
		}
		if (s == "check") {
			int index;
			cin >> index;
			if (arr[index])
			{
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		if (s=="remove")
		{
			int index;
			cin >> index;
			arr[index] = false;
		}
		if (s == "toggle") {
			int index;
			cin >> index;
			if (arr[index])
			{
				arr[index] = false;
			}
			else {
				arr[index] = true;
			}
		}
		if (s=="all") {
			fill(arr, arr + 21, true);
		}
		if (s=="empty") {
			fill(arr, arr + 21, false);
		}
	}
	return 0;
}

