//
//  main.cpp
//  BOJ_14499
//
//  Created by KJH on 2021/01/27.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 21;
int N,M;

int startX,startY;

int K;

int board[MAX][MAX];
int dice[7]={0};
vector<int> ord;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void solve(){
    int x = startX;
    int y = startY;
    for (int i=0; i<ord.size(); i++) {

        int nextX = x + dx[ord[i]];
        int nextY = y + dy[ord[i]];

        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
        {
            continue;
        }
        //주사위 굴려서 dice배열 업데이트
        //동
        if (ord[i] == 0)
        {
            int temp = dice[6];
            dice[6] = dice[3];
            dice[3]= dice[1];
            dice[1] = dice[4];
            dice[4] = temp;
        }
        //서
        if (ord[i] == 1)
        {
            int temp = dice[6];
            dice[6] = dice[4];
            dice[4]= dice[1];
            dice[1] = dice[3];
            dice[3] = temp;
        }
        //북
        if (ord[i] == 2)
        {
            int temp = dice[6];
            dice[6] = dice[2];
            dice[2]= dice[1];
            dice[1] = dice[5];
            dice[5] = temp;
        }
        //남
        if (ord[i] == 3)
        {
            int temp = dice[6];
            dice[6] = dice[5];
            dice[5]= dice[1];
            dice[1] = dice[2];
            dice[2] = temp;
        }
        //칸이 0인 경우
        if (board[nextX][nextY] == 0)
        {
            board[nextX][nextY] = dice[6];
        }
        //칸이 0이 아닌 경우
        else
        {
            dice[6] = board[nextX][nextY];
            board[nextX][nextY]=0; 
        }
        y = nextY;
        x = nextX;
        cout << dice[1] << endl;
    }
}

int main() {
    cin >> N >> M >> startX >> startY >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }
    for (int i=0; i<K; i++) {
        int temp;
        cin >> temp;
        ord.push_back(temp-1);
    }
    solve();
    return 0;
}
