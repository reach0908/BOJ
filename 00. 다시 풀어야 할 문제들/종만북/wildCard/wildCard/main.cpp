//
//  main.cpp
//  wildCard
//
//  Created by KJH on 2020/09/14.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool match(const string& w, const string& s){
    int pos=0;
    while (pos<s.size()&&pos<w.size()&&(w[pos]=='?'||w[pos]==s[pos])) {
        pos++;
    }
    //w끝에 도달한 경우 문자열의 사이즈와 패턴의 사이즈와 같은지 확인
    if (pos==w.size()) {
        return pos==s.size(); // 같다면 그둘은 매치가 된다.
    }
    if (w[pos]=='*') {
        for (int skip=0; pos+skip<=s.size(); ++skip) {
            if (match(w.substr(pos+1), s.substr(pos+skip))) {
                return true;
            }
        }
    }
    return false;
}

int cache[101][101];

string W,S;

bool matchMemoized(int w,int s){
    int& ret = cache[w][s];
    if (ret!=-1) {
        return ret;
    }
    while (s<S.size()&&w<W.size()&&(W[w]=='?'||W[w]==S[s])) {
        ++w;
        ++s;
    }
    if (w==W.size()) {
        return ret =(s==S.size());
    }
    if(W[w]=='*'){
        for (int skip=0; skip+s<=S.size(); ++skip) {
            if (matchMemoized(w+1, s+skip)) {
                return ret-1;
            }
        }
    }
    return ret=0;
}


int main(int argc, const char * argv[]) {

    return 0;
}
