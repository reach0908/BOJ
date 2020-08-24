//
//  main.cpp
//  BOJ_14500
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#define MAX_SIZE 500

using namespace std;

//테트로미노1
//0,0 0,1 0,2 0.3
//0,0 0,1 1,1 1,0
//0,0 1,0 2,0 2,1
//0,0 1,0 1,1 2,1
//0,0 0,1 1,1 0,2

int max(int a,int b){
    return a>b?a:b;
}

int t1(int(*arr)[500],int xstart,int xend,int ystart,int yend){
    int caseMax=0;
    //case1 - 가로
    while (1) {
        int sum=0;
        if (xend-xstart<4) {
            xstart=0;
            ystart++;
            if (ystart>yend) {
                break;
            }
        }else{
            sum=arr[ystart][xstart]+arr[ystart][xstart+1]
            +arr[ystart][xstart+2]+arr[ystart][xstart+3];
            caseMax = max(caseMax, sum);
            xstart++;
        }
    }
    //case2 - 세로
    while (1) {
        int sum=0;
        if (yend-ystart<4) {
            ystart=0;
            xstart++;
            if (xstart>xend) {
                break;
            }
        }else{
            sum=arr[ystart][xstart]+arr[ystart+1][xstart]
            +arr[ystart+2][xstart]+arr[ystart+3][xstart];
            caseMax = max(caseMax, sum);
            ystart++;
        }
       
    }
     return caseMax;
}
int t2(int(*arr)[500],int xstart,int xend,int ystart,int yend){
    int caseMax=0;
    //case1 - 가로
    while (1) {
        int sum=0;
        if (xend-xstart<2) {
            xstart=0;
            ystart++;
            if (yend-ystart<2) {
                break;
            }
        }else{
            sum=arr[ystart][xstart]+arr[ystart][xstart+1]
            +arr[ystart+1][xstart+1]+arr[ystart+1][xstart];
            caseMax = max(caseMax, sum);
            xstart++;
        }
    }
    
     return caseMax;
}
int t3(int(*arr)[500],int xstart,int xend,int ystart,int yend){
    int caseMax=0;
    //case1 - 가로
    while (1) {
        int sum=0;
        if (xend-xstart<2) {
            xstart=0;
            ystart++;
            if (yend-ystart<3) {
                break;
            }
        }else{
            sum=arr[ystart][xstart]+arr[ystart+1][xstart]
            +arr[ystart+2][xstart]+arr[ystart+2][xstart+1];
            caseMax = max(caseMax, sum);
            xstart++;
        }
    }
    //case2 - 세로
    while (1) {
        int sum=0;
        if (yend-ystart<4) {
            ystart=0;
            xstart++;
            if (xstart>xend) {
                break;
            }
        }else{
            sum=arr[ystart][xstart]+arr[ystart+1][xstart]
            +arr[ystart+2][xstart]+arr[ystart+3][xstart];
            caseMax = max(caseMax, sum);
            ystart++;
        }
       
    }
     return max(caseMax,caseMax);
}
int main(int argc, const char * argv[]) {
    int N,M;
    cin >> N >> M;
    int arr[MAX_SIZE][MAX_SIZE];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    int a[4];
    a[0] = t1(arr, 0, N, 0, M);
    a[1] = t2(arr, 0, N, 0, M);
    cout << a[0];
    return 0;
}
