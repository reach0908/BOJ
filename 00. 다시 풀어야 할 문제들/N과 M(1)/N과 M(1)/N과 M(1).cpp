

#include <iostream>

using namespace std;

int N, M;
int arr[9];
bool visited[9];

void func(int cnt) {
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <=N; i++) //경우의 수에대한 모든 탐색
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i; 
			func(cnt + 1); 
			visited[i] = false; //성공하기 전단계로 돌아가기
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

	func(0);
	return 0;
}

