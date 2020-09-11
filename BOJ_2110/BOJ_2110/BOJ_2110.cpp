
#include <iostream>
#include <algorithm>

#define MAX_SIZE 200000

using namespace std;

int N, C;
int house[MAX_SIZE];

bool func(int dist) {
	int cnt = 1;
	int prev = house[0];
	for (int i = 1; i < N; i++)
	{
		if (house[i]-prev >= dist)
		{
			cnt++;
			prev = house[i];
		}
	}
	if (cnt>=C)
	{
		return true;
	}
	return false;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}
	sort(house, house + N);

	int low = 1;
	int high = house[N - 1] - house[0];
	int result = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (func(mid))
		{
			result = max(result, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result << endl;
	return 0;
}

