

#include <iostream>
#include <vector>

using namespace std;

int t;
vector<int> v;


int main()
{
    cin >> t;
    v.resize(t);
    int maxLeft;
    int maxRight;
    int leftCnt;
    int rightCnt;
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
    }
    maxLeft = v[0];
    maxRight = v[t - 1];
    leftCnt = 1;
    rightCnt = 1;
    for (int i = 0; i < t; i++)
    {
        if (maxLeft<v[i])
        {
            maxLeft = v[i];
            leftCnt++;
        }
        if (maxRight<v[t-i-1])
        {
            maxRight = v[t - i-1];
            rightCnt++;
        }
    }
    cout << leftCnt << "\n" << rightCnt;
}
