// N과M(6).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 9;

using namespace std;

int N, M;
vector<int> v;
bool visited[MAX] = { false };

int arr[MAX];

void DFS(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i]) {

            visited[i] = true;
            arr[cnt] = v[i];
            if (arr[cnt] > arr[cnt - 1]) {
                DFS(cnt + 1);
            }
            visited[i] = false;
        }
    }
}


int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    DFS(0);
}

