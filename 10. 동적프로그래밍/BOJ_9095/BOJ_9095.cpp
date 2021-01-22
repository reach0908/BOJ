#include <iostream>

using namespace std;

const int MAX = 11;
int cache[MAX];

//점화식을 이용한 문제풀이
// 1 = 1;
// 2 = 11,2;
// 3 = 111,21,12,3
// 4 = 
void solve(){
    for (int i = 4; i < MAX; i++)
    {
        cache[i] = cache[i-1] + cache[i-2] + cache[i-3];
    }
}


int main()
{
    int t;
    cin >> t;
    cache[1]=1;
    cache[2]=2;
    cache[3]=4;
    solve();
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << cache[n] << endl;
    } 
    return 0;
}
