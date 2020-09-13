//
//  main.cpp
//  BOJ_2309
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>

using namespace std;

const int SIZE=9;
int arr[SIZE];

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b = temp;
}

void bubbleSort(int arr[],int SIZE){
    for (int i=0; i<SIZE-1; i++) {
        for (int j=0; j<SIZE-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    for (int i=0; i<SIZE; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, SIZE);
    int sum=0;
    int a,b;
    for (int i=0; i<SIZE; i++) {
        sum+=arr[i];
    }
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (sum - arr[i]-arr[j]==100) {
                a=i;
                b=j;
            }
        }
    }
    for (int i=0; i<SIZE; i++) {
        if (i==a||i==b) {
            continue;
        }
        cout << arr[i] << endl;
    }
}
