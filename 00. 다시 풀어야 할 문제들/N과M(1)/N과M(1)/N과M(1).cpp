
#include <iostream>
#include <vector>
using namespace std;

bool visited[9] = { false };
vector<int> v;
int N, M;
int arr[9];
void func(int cnt) {
	if (cnt==M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			func(cnt + 1);
			visited[i] = false;
		}
	}

}
int main()
{
	cin >> N >> M;
	func(0);
	return 0;
	
}

