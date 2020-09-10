

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T;


//자연수의 범위가 매우 한정적이므로 완전탐색으로 문제를 해결 할 수 있다.
// 수 리스트와 연산자 리스트를 

//재귀이용
void func(vector<int> numV,vector<char> v, int N) {
    int sum = 1;
    string s;
    s += "1";
    int j = 0;
    for (int i = 1; i < N; i++)
    {
       
            if (v[j] == ' ')
            {
                if (sum > 0)
                {
                    sum = sum * 10 + numV[i];
                }
                else
                {
                    sum = sum * 10 - numV[i];
                }
                s += " ";
                s += (numV[i] + '0');
                j++;
            }
            else if (v[j] == '+')
            {
                sum += numV[i];
                s += "+";
                s += (numV[i] + '0');
                j++;
            }
            else if (v[j] == '-')
            {
                sum -= numV[i];
                s += "-";
                s += (numV[i] + '0');
                j++;
            }
    }
    if (sum == 0)
    {
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
}
void oper(vector<int> numV,vector<char> v,int N) {
    if (v.size()==N-1)
    {
        func(numV,v,N);
        return;
    }
    else {
        v.push_back(' ');
        oper(numV,v,N);
        v.pop_back();

        v.push_back('+');
        oper(numV,v, N);
        v.pop_back();

        v.push_back('-');
        oper(numV,v, N);
        v.pop_back();
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
        vector<int> numV;
        cin >> temp;
        for (int i = 1; i <= temp; i++)
        {
            numV.push_back(i);
        }
        vector<char> operV;
        oper(numV,operV,temp);
        
    }
}

