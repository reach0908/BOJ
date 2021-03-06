﻿

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 9;

vector<int> v;
int arr[MAX] = {-1};
int N, M;
int check[10001] = { 0 };

void DFS(int cnt) {
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (arr[cnt]==v[i])
		{
			continue;
		}
		if (arr[cnt-1]<=v[i])
		{
			arr[cnt] = v[i];
			DFS(cnt + 1);
		}
		
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	DFS(0);

	return 0;
}

