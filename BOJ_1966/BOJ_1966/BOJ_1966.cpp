// BOJ_1966.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T;
int N;
int target;

struct Node {
    int num;
    int priority;

    bool operator > (const Node& other) {
        return this->priority > other.priority;
    }
};
bool desc(int a, int b) {
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++)
    {   
        cin >> N >> target;

        queue<Node> q;
        vector<int> prioNum;

        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            Node nodeTemp;
            nodeTemp.num = j;

            nodeTemp.priority = temp;
            prioNum.push_back(temp);

            q.push(nodeTemp);
        }
        sort(prioNum.begin(), prioNum.end(),desc);
        int index = 0;
        while (index!=N)
        {
            if (prioNum[index] == q.front().priority)
            {
                index++;
                if (q.front().num == target) {
                    break;
                }
                q.pop();
                
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
		cout << index << "\n";
    }
}

