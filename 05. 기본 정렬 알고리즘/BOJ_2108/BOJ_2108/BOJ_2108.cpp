

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 500001;
int N;
vector<int> v;
vector<pair<int, int>> freq;
int maxN = -1e9;
int minN = 1e9;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {

	if (p1.second == p2.second) {   
		return p1.first < p2.first; 
	}
	return p1.second > p2.second;    

}

int main()
{
    cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		maxN = max(maxN, v[i]);
		minN = min(minN, v[i]);
		sum += v[i]; 
		if (freq.empty()) {
			freq.push_back({ v[i],1 });
			continue;
		}
		if (freq.back().first == v[i]) {
			freq.back().second++;
		}
		else {
			freq.push_back({ v[i],1 });
		}
	}



	cout << floor((sum / N)+0.5) << endl;
	cout << v[N / 2] << endl;
	sort(freq.begin(), freq.end(), cmp);
	if (freq.size()>=2&&(freq[0].second == freq[1].second)) {
		cout << freq[1].first << endl;
	}
	else {
		cout << freq[0].first << endl;
	}
	cout << maxN - minN << endl;
	return 0;
}
