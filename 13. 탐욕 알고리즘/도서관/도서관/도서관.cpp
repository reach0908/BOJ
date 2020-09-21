
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

vector<int> over;
vector<int> under;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp < 0)
		{
			under.push_back(abs(temp));
		}
		else {
			over.push_back(temp);
		}
	}
	sort(over.begin(), over.end(), greater<int>());
	sort(under.begin(), under.end(), greater<int>());
	int MAX = 0;
	if (under.size()==0)
	{
		MAX = over[0];
	}
	else if(over.size()==0){
		MAX = under[0];
	}
	else {
		MAX = max(under[0], over[0]);
	}
	int result = 0;
	for (int i = 0; i < over.size(); i+=M)
	{
		result += over[i] * 2;
	}
	for (int i = 0; i < under.size(); i += M)
	{
		result += under[i] * 2;
	}
	result -= MAX;
	cout << result;
	return 0;
}
