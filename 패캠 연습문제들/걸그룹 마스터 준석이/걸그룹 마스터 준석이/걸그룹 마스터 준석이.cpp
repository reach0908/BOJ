
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MAX = 101;

int N, M;

vector<pair<string, vector<string>>> v;
unordered_map<string, int> hmap;

void prob1(string target) {

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < v[i].second.size(); j++)
		{
			if (v[i].second[j]==target)
			{
				cout << v[i].first << "\n";
				return;
			}
		}
	}
}

void prob2(string target) {
	unordered_map<string, int>::iterator it;
	it = hmap.find(target);
	sort(v[it->second].second.begin(), v[it->second].second.end());
	for (int i = 0; i < v[it->second].second.size(); i++)
	{
		cout << v[it->second].second[i] << "\n";
	}
	return;
}

int main()
{
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++)
	{
		string g_name;
		int num;
		cin >> g_name >> num;
		hmap.insert(make_pair(g_name, i));
		v[i].first = g_name;
		for (int j = 0; j < num; j++)
		{
			string memname;
			cin >> memname;
			v[i].second.push_back(memname);
		}
	}

	for (int i = 0; i < M; i++)
	{
		string target;
		int probNum;
		cin >> target >> probNum;
		if (probNum==1)
		{
			prob1(target);
		}
		else {
			prob2(target);
		}
	}
	return 0;
}

