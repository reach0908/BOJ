#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1001;
int N;

//클릭수 / 버퍼 있는지 없는지
long long cache[MAX];

long long solve(int cnt){
    long long &res = cache[cnt];
    if(res!=-1){
        return res;
    }
    res = 1+solve(cnt-1);
    if(cnt>=3){
        for (int i = 1; i <= cnt-2; i++)
        {
            res = max(res,solve((cnt-2)-i)*(i+1));
        }
    }
    return res;
}


int main(int argc, char const *argv[])
{
    cin >> N;
    memset(cache,-1,sizeof(cache));
    cache[0] =0;
    cout << solve(N);
    return 0;
}
