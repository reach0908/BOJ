// BOJ_1568.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999
using namespace std;

vector<int> comb;
vector<char> oper;


int T;

int MAX = -INF;
int MIN = INF;


int main()
{
    cin >> T;
	vector<int> num(T);
	for (int  i = 0; i < T; i++)
	{
		cin >> num[i];
	}
	int p, n, m, d;
	cin >> p >> n >> m >> d;
	for (int i = 0; i < p; i++)
	{
		oper.push_back('a');
	}
	for (int i = 0; i < n; i++)
	{
		oper.push_back('b');
	}
	for (int i = 0; i < m; i++)
	{
		oper.push_back('c');
	}
	for (int i = 0; i < d; i++)
	{
		oper.push_back('d');
	}
	do
	{
		int count=0;
		int sum = num[count];
		while (count<T-1)
		{
			char temp = oper[count];
			switch (temp)
			{
			case 'a':
				sum = sum + num[count + 1];
				break;
			case 'b':
				sum = sum - num[count + 1];
				break;
			case 'c':
				sum = sum * num[count + 1];
				break;
			case 'd':
				sum = sum / num[count + 1];
				break;
			}
			count++;
		}
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
	} while (next_permutation(oper.begin(),oper.end()));
	
	cout << MAX << endl << MIN;
}

