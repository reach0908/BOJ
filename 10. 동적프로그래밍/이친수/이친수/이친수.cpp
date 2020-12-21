

#include <iostream>

using namespace std;

const int MAX = 91;

int N;

long long cache[MAX] = { 0 };

int main()
{

    cache[1] = 1;
    cache[2] = 1;
   
    cin >> N;
    
    for (int i = 3; i <= N; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    cout << cache[N];
    return 0;
}
