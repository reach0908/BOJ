

#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    int index = 1;
    while (q.size()!=1)
    {
        int cur = q.front();
        q.pop();
        if (index % 2 == 0) {
            q.push(cur);
        }
        index++;
    }
    cout << q.front();
}
