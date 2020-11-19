

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

const int INF = 999999999;


int cache[MAX] = { 0};

int N;

void solve() {
    cache[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        cache[i] = cache[i - 1] + 1;
        if (i%3==0)
        {
            cache[i] = min(cache[i], cache[i / 3] + 1);
        }
        else if (i % 2 == 0) {
            cache[i] = min(cache[i], cache[i / 2] + 1);
        }
    }
}


int main()
{
    cin >> N;
    solve();
    cout << cache[N];
    return 0;

}

