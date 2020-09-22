// N과M(4).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
const int MAX = 9;
int N,M;
int arr[MAX] = {-1};
void DFS(int cnt) {
	if (cnt==M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		arr[cnt] = i;
		if (arr[cnt]>=arr[cnt-1])
		{
			DFS(cnt + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N>>M;
	DFS(0);
}

