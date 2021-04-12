
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, TC;

int main()
{
    cin >> TC;
	
	for (int i = 0; i < TC; i++)
	{
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			q.push({ temp,i });
			pq.push(temp);
		}
		int cnt = 0;
		while (!q.empty())
		{
			int curNum = q.front().first;
			int curOrd = q.front().second;
			q.pop();
			if (pq.top() == curNum) {
				cnt++;
				pq.pop();
				if (curOrd == M) {
					break;
				}
			}
			else {
				q.push({ curNum,curOrd });
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
