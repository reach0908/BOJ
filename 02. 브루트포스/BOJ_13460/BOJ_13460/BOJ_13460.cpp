

#include<iostream>
#include<queue>
#include<algorithm>

#define INF 1e9

using namespace std;
typedef struct options {
    int depth;
    int ry, rx, by, bx;
}options;
int N, M;
int srx, sry, sbx, sby, ex, ey;
int ans = -1;
int board[11][11];
int visited[11][11][11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
    queue < options > q;
    options op = { 0,sry,srx,sby,sbx };
    q.push(op);
    visited[sry][srx][sby][sbx] = 1;
    while (!q.empty()) {
        options now = q.front();
        q.pop();
        if (now.depth > 10)
            break;
        if (now.ry == ey && now.rx == ex) {
            ans = now.depth;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ry = now.ry; int rx = now.rx;
            int by = now.by; int bx = now.bx;
            while (1) {
                ry += dy[i];
                rx += dx[i];
                if (board[ry][rx] == 1) {
                    ry -= dy[i];
                    rx -= dx[i];
                    break;
                }
                else if (board[ry][rx] == 2)
                    break;
            }
            while (1) {
                by += dy[i];
                bx += dx[i];
                if (board[by][bx] == 1) {
                    by -= dy[i];
                    bx -= dx[i];
                    break;
                }
                else if (board[by][bx] == 2)
                    break;
            }
            if (by == ey && bx == ex)
                continue;
            if (by == ry && bx == rx) {
                switch (i) {
                case 0:
                    if (now.rx < now.bx) bx++;
                    else rx++;
                    break;
                case 1:
                    if (now.rx < now.bx) rx--;
                    else bx--;
                    break;
                case 2:
                    if (now.ry < now.by) by++;
                    else ry++;
                    break;
                case 3:
                    if (now.ry < now.by) ry--;
                    else by--;
                    break;
                }
            }
            if (visited[ry][rx][by][bx] == 0) {
                visited[ry][rx][by][bx] = 1;
                options next = { now.depth + 1,ry,rx,by,bx };
                q.push(next);
            }
        }
    }
}

int main() {
    string s;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            switch (s[j]) {
            case '#':
                board[i][j + 1] = 1;
                break;
            case '.':
                board[i][j + 1] = 0;
                break;
            case 'R':
                sry = i;
                srx = j + 1;
                break;
            case 'B':
                sby = i;
                sbx = j + 1;
                break;
            case 'O':
                ey = i;
                ex = j + 1;
                board[i][j + 1] = 2;
                break;
            }
        }
    }
    bfs();
    printf("%d\n", ans);
}
