//
//  main.cpp
//  BOJ_6588
//
//  Created by KJH on 2020/08/24.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
int minFactor[MAX];
vector<int> prime; //소수


/*bool primeCheck(int num){
    if (num%2==0||num==1) {
        return false;
    }
    for (int i=3; i<num; i++) {
        if (num%i==0) {
            return false;
        }
    }
    return true;
}*/

//에라토스테네스의 체
void eratosthenes(void)
{
        minFactor[0] = minFactor[1] = -1;
        for (int i = 2; i < MAX; i++)
                 minFactor[i] = i;
        for (int i = 2; i*i < MAX; i++)
            if (minFactor[i] == i)
                for (int j = i * i; j < MAX; j += i)
                    if (minFactor[j] == j)
                        minFactor[j] = i;
        //홀수인 소수를 저장
        for (int i = 3; i < MAX; i++)
                 if (minFactor[i] == i)
                         prime.push_back(i);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    eratosthenes();
    while (1){
        int N;
        cin >> N;
        if (N == 0)
            break;
//소수를 탐색하며
        for(int i=0; i<prime.size(); i++)
                             //N - prime[i]도 소수인 수를 찾는다
            if (minFactor[N - prime[i]] == N - prime[i]){
                cout << N << " = " << prime[i] << " + " << N - prime[i]<<"\n";
                 break;
            }
    }
    /*while (1) {
        int num,a,b;
        cin >>num;
        if (num==0) {
            break;
        }
        int i=3;
        while (1) {
            if (num-i<0) {
                cout << "Goldbach's conjecture is wrong." << endl;
            }
            if (primeCheck(i)&&primeCheck(num-i)) {
                a=i;
                b=num-i;
                break;
            }
            i++;
        }
        cout << num<<" = "<<a<<" + "<<b << endl;
    }*/
    return 0;
}
