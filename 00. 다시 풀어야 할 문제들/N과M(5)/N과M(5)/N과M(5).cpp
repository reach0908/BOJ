
#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 9;
using namespace std;
int N, M;
int arr[MAX];

vector<int> v;
bool visited[MAX] = { false };
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
        if (!visited[i])
        {
            visited[i] = true;
            arr[cnt] = v[i];
            DFS(cnt + 1);
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
