

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 21;
const int INF = 999999999;
int N;
vector<int> team;
int players[MAX][MAX] = {0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2) {
			team.push_back(0);
		}
		else {
			team.push_back(1);
		}
		for (int j = 0; j < N; j++)
		{
			cin >> players[i][j];
		}
	}
	int result = INF;
	do
	{
		
		int tempA = 0;
		int tempB = 0;
		int temp = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				
					if (team[i] == 0 && team[j] == 0)
					{
						tempA += players[i][j];
						
					}
					else if (team[i] == 1 && team[j] == 1) {
						tempB += players[i][j];
						
					}
				
			}
		}
		
		temp = abs(tempA - tempB);
		result = min(result, temp);
	} while (next_permutation(team.begin(),team.end()));
	cout << result;

	return 0;
}

