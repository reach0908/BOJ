//
//  main.cpp
//  뒤집기
//
//  Created by KJH on 2020/09/17.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int check1(){
    int count =0;
    char checkS = '1';
    for (int i=0; i<=s.size(); i++) {
        if (s[i]==checkS) {
            for (int j=i; j<=s.size(); j++) {
                if (s[j]!=checkS) {
                    i=j-1;
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

int check2(){
   int count =0;
   char checkS = '0';
   for (int i=0; i<=s.size(); i++) {
       if (s[i]==checkS) {
           for (int j=i; j<=s.size(); j++) {
               if (s[j]!=checkS) {
                   i=j-1;
                   count++;
                   break;
               }
           }
       }
   }
   return count;
}

int main(){
    cin >> s;
    cout << min(check1(),check2());
    return 0;
}
