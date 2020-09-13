//
//  main.cpp
//  BOJ_11723
//
//  Created by KJH on 2020/09/04.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>

int T;

using namespace std;

vector<bool> v(21);

void add(int a){
    if (v[a]) {
        return;
    }
    else{
        v[a] = true;
    }
    
}
int check(int a){

    if (v[a]) {
        return 1;
    }
    else{return 0;}
}
void remove(int a){
    if (v[a]) {
        v[a]=false;
    }
    else{
        return;
    }
}
void toggle(int a){
    
    if (v[a]) {
        v[a]=false;
    }
    else{
        v[a]=true;
    }
}
void empty(){
    
    for (int i=1; i<21;i++) {
        v[i]=false;
    }
}
void all(){
    
    for (int i=1; i<21;i++) {
        v[i]=true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    empty();
    for (int i=0; i<T; i++) {
        string s;
        int num;
        cin >> s;
        if (s=="add") {
            cin >> num;
            add(num);
        }
        else if (s=="check") {
            cin >> num;
            cout << check(num) <<"\n";
        }
        else if(s=="remove"){
            cin >> num;
            remove(num);
        }
        else if(s=="all"){
            all();
        }
        else if(s=="empty"){
            empty();
        }
        else if(s=="toggle"){
            cin>>num;
            toggle(num);
        }
    }
    return 0;
}
