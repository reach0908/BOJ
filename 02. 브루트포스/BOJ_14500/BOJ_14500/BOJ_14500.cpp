#include <iostream>
#define MAX_SIZE 500
int arr[MAX_SIZE][MAX_SIZE] = { 0, };
using namespace std;

//테트로미노1
//0,0 0,1 0,2 0.3
//0,0 0,1 1,1 1,0
//0,0 1,0 2,0 2,1
//0,0 1,0 1,1 2,1
//0,0 0,1 1,1 0,2

int max(int a, int b) {
    return a > b ? a : b;
}

int t1(int(*arr)[500], int xstart, int xend, int ystart, int yend) {
    int caseMax = 0;
    //case1 - 가로
    while (1) {
        int sum = 0;
        if (xend - xstart < 3) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 0) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart][xstart + 1]
                + arr[ystart][xstart + 2] + arr[ystart][xstart + 3];
            caseMax = max(caseMax, sum);
            xstart++;
        }
    }
    xstart = 0;
    ystart = 0;
    //case2 - 세로
    while (1) {
        int sum = 0;
        if (xend - xstart < 0) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 3) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart + 1][xstart]
                + arr[ystart + 2][xstart] + arr[ystart + 3][xstart];
            caseMax = max(caseMax, sum);
            xstart++;
        }

    }
    xstart = 0;
    ystart = 0;
    return caseMax;
}
int t2(int(*arr)[500], int xstart, int xend, int ystart, int yend) {
    int caseMax = 0;
    //case1 - 가로
    while (1) {
        int sum = 0;
        if (xend - xstart < 1) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 1) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart][xstart + 1]
                + arr[ystart + 1][xstart + 1] + arr[ystart + 1][xstart];
            caseMax = max(caseMax, sum);
            xstart++;
        }
    }
    xstart = 0;
    ystart = 0;
    return caseMax;
}
int t3(int(*arr)[500], int xstart, int xend, int ystart, int yend) {
    int caseMax = 0;
    //case1 - 가로
    while (1) {
        int sum = 0;
        if (xend - xstart < 1) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 2) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart + 1][xstart]
                + arr[ystart + 2][xstart] + arr[ystart + 2][xstart + 1];
            caseMax = max(caseMax, sum);
            xstart++;
        }
    }
    xstart = 0;
    ystart = 0;//정방향
    while (1) {
        int sum = 0;
        if (xend - xstart < 2) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 1) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart][xstart + 1]
                + arr[ystart][xstart + 2] + arr[ystart + 1][xstart];
            caseMax = max(caseMax, sum);
            xstart++;
        }

    }
    xstart = 0;
    ystart = 0;
    while (1) {
        int sum = 0;
        if (xend - xstart < 1) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 2) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart][xstart + 1]
                + arr[ystart + 1][xstart + 1] + arr[ystart + 2][xstart + 1];
            caseMax = max(caseMax, sum);
            xstart++;
        }

    }
    xstart = 0;
    ystart = 0;
    while (1) {
        int sum = 0;
        if (xend - xstart < 2) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 1) {
                break;
            }
        }
        else {
            sum = arr[ystart + 1][xstart] + arr[ystart + 1][xstart + 1]
                + arr[ystart + 1][xstart + 2] + arr[ystart][xstart + 2];
            caseMax = max(caseMax, sum);
            xstart++;
        }

    }
    xstart = 0;
    ystart = 0;
    return caseMax;
}
int t4(int(*arr)[500], int xstart, int xend, int ystart, int yend) {
    int caseMax = 0;
    //case1 - 가로
    while (1) {
        int sum = 0;
        if (xend - xstart < 1) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 2) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart + 1][xstart]
                + arr[ystart + 1][xstart + 1] + arr[ystart + 2][xstart + 1];
            caseMax = max(caseMax, sum);
            xstart++;
        }
    }
    xstart = 0;
    ystart = 0;//정방향
    while (1) {
        int sum = 0;
        if (xend - xstart < 2) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 1) {
                break;
            }
        }
        else {
            sum = arr[ystart + 1][xstart] + arr[ystart + 1][xstart + 1]
                + arr[ystart][xstart + 1] + arr[ystart][xstart + 2];
            caseMax = max(caseMax, sum);
            xstart++;
        }

    }
    xstart = 0;
    ystart = 0;
    return caseMax;
}
int t5(int(*arr)[500], int xstart, int xend, int ystart, int yend) {
    int caseMax = 0;
    //case1 - 가로
    while (1) {
        int sum = 0;
        if (xend - xstart < 2) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 1) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart][xstart + 1]
                + arr[ystart + 1][xstart + 1] + arr[ystart][xstart + 2];
            caseMax = max(caseMax, sum);
            xstart++;
        }
    }
    xstart = 0;
    ystart = 0;
    while (1) {
        int sum = 0;
        if (xend - xstart < 1) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 2) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart + 1] + arr[ystart + 1][xstart + 1]
                + arr[ystart + 2][xstart + 1] + arr[ystart + 1][xstart];
            caseMax = max(caseMax, sum);
            xstart++;
        }

    }
    xstart = 0;
    ystart = 0;
    while (1) {
        int sum = 0;
        if (xend - xstart < 2) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 1) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart + 1] + arr[ystart + 1][xstart]
                + arr[ystart + 1][xstart + 1] + arr[ystart + 1][xstart + 2];
            caseMax = max(caseMax, sum);
            xstart++;
        }

    }
    xstart = 0;
    ystart = 0;
    while (1) {
        int sum = 0;
        if (xend - xstart < 1) {
            xstart = 0;
            ystart++;
            if (yend - ystart < 2) {
                break;
            }
        }
        else {
            sum = arr[ystart][xstart] + arr[ystart + 1][xstart]
                + arr[ystart + 1][xstart + 1] + arr[ystart + 2][xstart];
            caseMax = max(caseMax, sum);
            xstart++;
        }

    }
    xstart = 0;
    ystart = 0;
    return caseMax;
}
int main(int argc, const char* argv[]) {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int a[5];
    a[0] = t1(arr, 0, M - 1, 0, N - 1);
    a[1] = t2(arr, 0, M - 1, 0, N - 1);
    a[2] = t3(arr, 0, M - 1, 0, N - 1);
    a[3] = t4(arr, 0, M - 1, 0, N - 1);
    a[4] = t5(arr, 0, M - 1, 0, N - 1);

    int maxNum = 0;
    for (int i = 0; i < 5; i++)
    {
        maxNum = max(a[i], maxNum);
    }
    cout << maxNum;
    return 0;
}