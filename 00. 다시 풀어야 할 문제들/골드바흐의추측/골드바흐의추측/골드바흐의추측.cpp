

#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

bool eratos(int n) {
	if (n==1||n%2==0)
	{
		return false;
	}
	int k = (int)sqrt(n);
	for (int i = 3; i <=k; i++)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}

void goldbach(vector<pair<int, int>> &result, int n,int count) {
	for (int i = 3; i < n; i++)
	{
		if (eratos(i)&&eratos(n-i))
		{
			result[count].first = i;
			result[count].second = n - i;
			cout << num[count] << " = " << result[count].first << " + " << result[count].second << "\n";
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1)
	{
		int temp;
		cin >> temp;
		if (temp==0)
		{
			break;
		}
		num.push_back(temp);
	}
	int k = num.size();
	vector<pair<int, int>> result;
	result.resize(k);
	for (int i = 0; i < k; i++)
	{
		goldbach(result, num[i], i);
		
	}
}

