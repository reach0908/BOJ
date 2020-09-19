
#include <iostream>
#include <vector>
using namespace std;

int N,S;
vector<int> num;
int result=0;


void DFS(int i, int sum) {
	if (i == N) return;
	if (sum+num[i]==S)
	{
		result++;
	}
	DFS(i + 1, sum); // 이번거는 스킵하고 다음 원소부터의 부분수열
	DFS(i + 1, sum + num[i]); // 이번거를 포함하는 부분수열

}

int main()
{
    cin >> N >> S;
	num.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	DFS(0, 0);
	cout << result;
}

