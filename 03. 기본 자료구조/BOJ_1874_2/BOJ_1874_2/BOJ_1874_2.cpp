

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int MAX = 100001;

int N;

vector<int> v;
vector<char> c;
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int index = 0;
	for (int i = 1; i <= N; i++)
	{
		s.push(i);
		c.push_back('+');
		while (!s.empty() && s.top() == v[index])
		{
			s.pop();
			c.push_back('-');
			index++;
		}
		
	}
	if (!s.empty()) {
		cout << "NO" << "\n";
		
	}
	else {
		for (int i = 0; i < c.size(); i++)
		{
			cout << c[i] << "\n";
		}
	}
	return 0;
}
