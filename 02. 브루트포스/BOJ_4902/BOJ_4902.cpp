#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 7;
int v[401][800], pSum[401][800];

int main() {
	int n, cnt = 0;
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				cin >> v[i][j];
				pSum[i][j] = v[i][j] + pSum[i][j - 1];
			}
		}
		int mx = -INF;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2 * i - 1; j += 2) {
				for (int k = 0, t = 0; k < n - i + 1; k++) {
					t += pSum[i + k][j + 2 * k] - pSum[i + k][j - 1];
					mx = max(mx, t);
				}
			}
		}
		for (int i = n; i >= 1; i--) {
			for (int j = 2; j <= 2 * i - 1; j += 2) {
				for (int k = 0, t = 0; k < min(j / 2, i - j / 2); k++) {
					t += pSum[i - k][j] - pSum[i - k][j - 2 * k - 1];
					mx = max(mx, t);
				}
			}
		}
		cout << ++cnt << ". " << mx << '\n';
	}
}
