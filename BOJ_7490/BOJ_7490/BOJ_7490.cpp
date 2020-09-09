

#include <iostream>
#include <vector>

using namespace std;

int T;
vector<string> v;

void func(int N,int sum,int num,int index) {
   
    if (index > 2*N-3) {
        if (sum==0)
        {
            for (int i = 0; i < v.size()-1; i++)
            {
                cout << v[i];
            }
            cout << endl;
        }
        else
        {
            return;
        }
    }
    else {
       
        v[index + 1] = " ";
        v[index + 2] = num + 1 + '0';
        if (sum<0)
        {
            func(N, (sum * 10 - num), num + 1, index + 2);
        }
        else if (sum >= 0) {
            func(N, (sum * 10 + num), num + 1, index + 2);
        }
        v[index + 1] = "+";
        v[index + 2] = num + 1 + '0';
        func(N, sum + num, num + 1, index + 2);
        v[index + 1] = "-";
        v[index + 2] = num + 1 + '0';
        func(N, sum - num, num + 1, index + 2);
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int temp;
        cin >> temp;
        v.resize(2*temp);
        int sum = 1;
        v[0] = '1';
        func(temp, sum,1,0);
    }
    
    return 0;
}

