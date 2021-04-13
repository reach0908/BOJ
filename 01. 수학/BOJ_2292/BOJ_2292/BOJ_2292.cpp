

#include <iostream>

using namespace std;

int N;


int solve(int num) {
    int cnt = 0;
    for (int i = 1; i < num; i+=(6*cnt))
    {
        cnt++;
    }
    return cnt+1;
}

int main()
{
    cin >> N;
    cout << solve(N) << endl;
    return 0;
    
}
