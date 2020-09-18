

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
int MIN = INT_MAX;
int MAX = -INT_MAX;

int N;
vector<int> num;

void DFS(int plus,int minus,int multi,int div,int count, int sum) {
	if (count == N)
	{
		MIN = min(MIN, sum);
		MAX = max(MAX, sum);
	}
	if (plus>0)
	{
		DFS(plus - 1, minus, multi, div, count + 1, sum + num[count]);
	}
	if (minus > 0)
	{
		DFS(plus, minus-1, multi, div, count + 1, sum - num[count]);
	}
	if (multi > 0)
	{
		DFS(plus , minus, multi-1, div, count + 1, sum * num[count]);
	}
	if (div > 0)
	{
		DFS(plus , minus, multi, div-1, count + 1, sum / num[count]);
	}

}

int main()
{
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	int oper[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}
	DFS(oper[0], oper[1], oper[2], oper[3], 1, num[0]);
	cout << MAX << endl;
	cout << MIN << endl;
	return 0;
}

