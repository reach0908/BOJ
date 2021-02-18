#include <iostream>
#include <vector>
#include <cmath>

const int MAX = 11;
using namespace std;

int N,K;
vector<int> c;
bool num[361]={0};

int H[MAX];
bool isOk[MAX];
int main(int argc, char const *argv[])
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        c.push_back(temp);
        num[temp]=true;
    }
    //빼기
    while (1)
    {
        bool flag = false;
        for (int i = 0; i < c.size(); i++)
        {
            for (int j = 0; j < c.size(); j++)
            {
                int temp1 = (abs(c[i]-c[j]))%360;
                int temp2 = (abs(c[i]+c[j]))%360;
                if(!num[temp1]){
                    flag = true;
                    num[temp1] = true;
                    c.push_back(temp1);
                }
                if(!num[temp2]){
                    flag = true;
                    num[temp2] = true;
                    c.push_back(temp2);
                }
            }
        }
        if(!flag){
            break;
        }
    }
    for (int i = 0; i < K; i++)
    {
        cin >> H[i];
    }
    for (int i = 0; i < K; i++)
    {
        if(!num[H[i]]){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
