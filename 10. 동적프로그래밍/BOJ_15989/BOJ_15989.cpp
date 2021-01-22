#include <iostream>

using namespace std;
const int MAX = 10001;
int cache[MAX][3];

void solve(){
    cache[1][0]=1;
    cache[2][0]=1;
    cache[2][1]=1;
    cache[3][0]=1;
    cache[3][1]=1;
    cache[3][2]=1;
    for (int i = 4; i < MAX; i++)
    {
        cache[i][0] = cache[i-1][0];
        cache[i][1] = cache[i-2][0] + cache[i-2][1];
        cache[i][2]=cache[i-3][0] + cache[i-3][1] + cache[i-3][2];
    }
    
}

int main(int argc, char const *argv[])
{
    int t,n;
    cin >> t;
    solve();
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int sum = cache[n][0] + cache[n][1] + cache[n][2];
        cout << sum << endl;
    }
    
    return 0;
}
