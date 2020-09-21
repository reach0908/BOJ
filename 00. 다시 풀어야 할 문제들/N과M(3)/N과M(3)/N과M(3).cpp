

#include <iostream>
const int MAX = 9;
using namespace std;

int arr[MAX];
int N, M;

void func(int cnt) {
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
		func(cnt + 1);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;
    func(0);
}
