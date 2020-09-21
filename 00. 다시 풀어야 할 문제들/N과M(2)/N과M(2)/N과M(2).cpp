// N과M(2).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
const int MAX = 9;
using namespace std;

int arr[9] = {0};
int N, M;
bool visited[MAX];
void func(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i]) {
            if (arr[cnt-1]<i)
            {
                visited[i] = true;
                arr[cnt] = i;
                func(cnt + 1);
                visited[i] = false;
            }
        }
    }

}

int main()
{
    cin >> N >> M;
    func(0);
    return 0;
}

