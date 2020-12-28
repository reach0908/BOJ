

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;

int A[MAX];

int cache[MAX][2] = {0};

int N=0;
void solve() {

    int ans = A[0];
    for (int i = 0; i < N; i++) {
        cache[i][0] = cache[i][1] = A[i];
        if (i == 0) continue;
        cache[i][0] = max(cache[i - 1][0] + A[i], A[i]);
        cache[i][1] = max(cache[i - 1][0], cache[i - 1][1] + A[i]);
        ans = max(ans, max(cache[i][0], cache[i][1]));
    }
    cout << ans << '\n';
}

int main()
{
    cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	solve();

    return 0;
}
