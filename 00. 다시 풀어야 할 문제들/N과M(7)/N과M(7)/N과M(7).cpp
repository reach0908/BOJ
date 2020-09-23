
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v;

int arr[8];

void DFS(int cnt) {
	if (cnt == M)
	{
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		arr[cnt] = v[i];
		DFS(cnt+1);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	DFS(0);
}

