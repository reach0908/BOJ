// 배2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> crane;
vector<int> box;
bool visited[10001] = {false};
int time = 0;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		crane.push_back(temp);
	}
	sort(crane.begin(), crane.end(),greater<int>());

	cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		box.push_back(temp);
	}
	sort(box.begin(), box.end(), greater<int>());
	if (crane[0] < box[0])
	{
		cout << -1;
		return 0;
	}
	while (1) {
		time++;
		for (int i = 0; i < N; i++) {

			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}

		if (box.size() == 0)
			break;

	}
	cout << time;
}


