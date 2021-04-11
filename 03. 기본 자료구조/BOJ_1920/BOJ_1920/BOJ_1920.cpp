
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 100000;
int N,M;
vector<int> nv;
vector<int> mv;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nv.push_back(temp);
	}
	sort(nv.begin(),nv.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		mv.push_back(temp);
	}
	for (int i = 0; i < M; i++)
	{
		bool find = false;
		int left = 0;
		int right = N-1;
		while (left<=right)
		{
			int mid = (left + right) / 2;
			if (nv[mid] == mv[i]) {
				find = true;
				break;
			}
			if (nv[mid]<mv[i]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		if (find) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

}

