#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n,k;
const int MAX = 100001;
const int INF = 1e9;
int cache[MAX];
vector<int> coin;

void solve(){
    cache[0]=0;
    for (int i = 1; i <=k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(cache[i]==1){
                break;
            }
            else if(i-coin[j]<0||cache[i-coin[j]]==INF){
                continue;
            }
            else{
                cache[i] = min(cache[i],cache[i-coin[j]]+1);
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    cin >> n >> k;
    
    for (int i = 1; i <=k; i++)
    {
        cache[i]=INF;
    }
    
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        coin.push_back(temp);
        cache[coin[i]]=1;
    }
    solve();
    if(cache[k]==INF){
        cout << -1 << endl;
    }
    else{
        cout << cache[k];
    }
    return 0;
}
