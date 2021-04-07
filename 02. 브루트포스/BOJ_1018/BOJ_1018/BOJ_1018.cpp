#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 50;
const int INF = 1e9;
int board[MAX][MAX];
int chess[8][8];
int N, M;
int result = INF;

pair<int, int> moveDir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

int rechess(int y, int x) {
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chess[i][j] = board[i + y][j + x];
        }
    }

    // w = 1
    // b = 0

    int wbcnt=0;
    int bwcnt=0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == chess[i][j]) {
                wbcnt++;
            }
            if ((i + j + 1) % 2 == chess[i][j]) {
                bwcnt++;
            }
        }
    }
    return min(wbcnt, bwcnt);
}

void solve() {

    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            result = min(result, rechess(i, j));
        }
    }
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) {
            char temp;
            cin >> temp;
            if (temp == 'W') {
                board[i][j] = 1;
            }
            else {
                board[i][j] = 0;
            }
        }
    }
    solve();
    return 0;
}
