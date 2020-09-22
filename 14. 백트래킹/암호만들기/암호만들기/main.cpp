//
//  main.cpp
//  암호만들기
//
//  Created by KJH on 2020/09/22.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int L,C;
char v[16];

void DFS(int index,int jacount,int mocount,string result){
    
    if (result.size() == L) {
        if (mocount>=1&&jacount>=2) {
            cout << result << endl;
        }
        return;
    }
    if (index==C) {
        return;
    }
    if (v[index]=='a'||v[index]=='e'||v[index]=='i'||v[index]=='o'||v[index]=='u'){
        DFS(index+1,jacount,mocount+1,result+v[index]);
    }else{
        DFS(index+1,jacount+1,mocount,result+v[index]);
    }
    DFS(index+1,jacount,mocount,result);
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> L >> C;
    for (int i=0; i<C; i++) {
        cin >> v[i];
    }
    sort(v, v+C);
    DFS(0,0,0,"");
    return 0;
}
