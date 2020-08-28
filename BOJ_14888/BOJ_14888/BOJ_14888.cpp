// BOJ_14888.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999

using namespace std;

int compareMin(int a, int b) {
	return a > b ? b : a;
}
int compareMax(int a, int b) {
	return a > b ? a : b;
}

int minNum=INF;
int maxNum = -INF;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int plus,minus,mul,div;
	cin >> plus >> minus >> mul >> div;

	vector<char> operV(N - 1);

	int i, j, k, l;

	for (i=0; i < plus; i++)
	{
		operV[i] = 'a';
	}
	for (j=i; j < i+minus; j++)
	{
		operV[j] = 'b';
	}
	for (k=j; k < j+mul; k++)
	{
		operV[k] = 'c';
	}
	for (l=k;l<k+div; l++)
	{
		operV[l] = 'd';
	}



	do
	{
		int count = 0;
		int sum = v[0];

		while (count < N-1)
		{
			char operTmp = operV[count];
			switch (operTmp)
			{
			case 'a':
				sum = sum + v[count+1];
				break;
			case 'b':
				sum = sum - v[count+1];
				break;
			case 'c':
				sum = sum * v[count+1];
				break;
			case 'd':
				sum = sum / v[count + 1];
				break;
			}
			count++;
		}
		maxNum = compareMax(maxNum, sum);
		minNum = compareMin(minNum, sum);	
	} while (next_permutation(operV.begin(), operV.end()));

	cout << maxNum << endl;
	cout << minNum << endl;

	return 0;
}








/*int main()
{
	int N;
	cin >> N;
	int T = N - 1;
	vector<int> v(N);
	for (int  i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	int plus;
	int minus;
	int mul;
	int div;
	cin >> plus >> minus >> mul >> div;
	int min = INF;
	int max = 0;
	do
	{
		min = INF;
		int count = 0;
		int opCnt = 0;
		int sum = v[count];
		while (plus > opCnt)
		{
			sum =sum +  v[count + 1];
			cout << sum << endl;
			count++;
			opCnt++;
		}
		opCnt = 0;
		while (minus > opCnt)
		{
			sum = sum -  v[count + 1];
			cout << sum << endl;
			count++;
			opCnt++;
		}
		opCnt = 0;
		while (mul > opCnt)
		{
			sum = sum * v[count + 1];
			cout << sum << endl;
			count++;
			opCnt++;
		}
		opCnt = 0;
		while (div > opCnt)
		{
			sum = sum / v[count + 1];
			cout << sum << endl;
			count++;
			opCnt++;
		}
		max = compareMax(max, sum);
		min = compareMin(min, sum);
		cout << "min :" << min << endl;
	} while (next_permutation(v.begin(),v.end()));
	cout << "Last Max : " << max<< endl;
	cout <<"Last Min : "<< min;
    return 0;
}*/

