

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//백준 14501


vector<int> result;

struct node
{
    int T;
    int P;
};


int maxCompare(int a, int b) {
    return a > b ? a : b;
}

int func(vector<node> v, int startDay, int sum, int Day) {
    int maxSum = 0;
    int nextStartDay = startDay + v[startDay].T;
     
    if (Day-(v[startDay].T+startDay) < 0) {
        return 0;
    }

    sum += v[startDay].P;
   
    for (int i = nextStartDay; i < Day; i++)
    {
        int tempSum = 0;
        tempSum = func(v, i, tempSum, Day);
        maxSum = maxCompare(maxSum, tempSum);
    }
    return sum + maxSum;
}


int main()
{
    int day = 0;
    cin >> day;
    vector<node> v(day);
    for (int i = 0; i < day; i++)
    {
        cin >> v[i].T;
        cin >> v[i].P;
    }
    
    for (int i = 0; i < day; i++)
    {
        int sum = 0;
        sum = func(v, i, 0, day);
        result.push_back(sum);
    }
    int maxSum = 0;
    for (int i = 0; i < result.size(); i++)
    {
        maxSum = maxCompare(maxSum, result[i]);
    }
    cout << maxSum;
}
