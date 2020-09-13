//
//  main.cpp
//  BOJ_2751
//
//  Created by KJH on 2020/09/10.
//  Copyright © 2020 KJH. All rights reserved.
//
// 우선 머지소트로 풀어보기




#include <iostream>
#include <vector>
#define MAX_SIZE 1000000
using namespace std;

//int sorted[MAX_SIZE];
int T;

/*void merge(int arr[],int start,int mid,int end){
    int i=start;
    int j=mid+1;
    int k=start;
    while (i<=mid&&j<=end) {
        if (arr[i]<arr[j]) {
            sorted[k] = arr[i];
            i++;
        }
        else{
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i>mid) {
        for (int t=j; t<=end; t++) {
            sorted[k] = arr[t];
            k++;
        }
    }else{
        for (int t=i; t<=mid; t++) {
            sorted[k] = arr[t];
            k++;
        }
    }
    for (int t=start; t<=end; t++) {
        arr[t] = sorted[t];
    }
}

void mergeSort(int arr[], int start,int end){
    int mid;
    if (start<end) {
        mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr,start,mid,end);
    }
}*/



int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arrV;
    cin >> T;
    //int arr[T];
    for (int i=0; i<T; i++) {
        int temp;
        cin >> temp;
        arrV.push_back(temp);
    }
    sort(arrV.begin(),arrV.end());
    //mergeSort(arr,0,T-1);
    for(int i=0;i<T;i++){
        cout << arrV[i] << "\n";
    }
    return 0;
}
