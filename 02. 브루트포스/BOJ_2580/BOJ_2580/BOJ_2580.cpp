

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 9;

int sdoku[MAX][MAX];

bool row[MAX][MAX + 1];
bool col[MAX][MAX + 1];
bool square[MAX][MAX + 1];

int change2SquareIdx(int y,int x) {
    return (y / 3) * 3 + x / 3;
}

void solve(int sqNum) {
    if (sqNum == 81) {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cout << sdoku[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }
    int y = sqNum / 9;
    int x = sqNum % 9;
    if (sdoku[y][x])
    {
        solve(sqNum + 1);
    }
    else {
        for (int k = 1; k <=MAX; k++)
        {
            if (!col[x][k] && !row[y][k] && !square[change2SquareIdx(y, x)][k]) {
                sdoku[y][x] = k;
                col[x][k] = true;
                row[y][k] = true;
                square[change2SquareIdx(y, x)][k] = true;
                solve(sqNum + 1);
                sdoku[y][x] = 0;
                col[x][k] = false;
                row[y][k] = false;
                square[change2SquareIdx(y, x)][k] = false;
            
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> sdoku[i][j];
            if (sdoku[i][j]) {
                col[j][sdoku[i][j]] = true;
                row[i][sdoku[i][j]] = true;
                square[change2SquareIdx(i, j)][sdoku[i][j]] = true;
                
            }
        }
    }
    solve(0);
    return 0;
}

