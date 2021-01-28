#include <iostream>
#include <queue>
#include <deque>

using namespace std;
const int MAX = 1001;
int T,K;
deque<int> topni[MAX];
int main(int argc, char const *argv[])
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.length(); j++)
        {
            topni[i].push_back(temp[j]-'0');
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int num,dir;
        cin >> num >> dir;
        int idx = num;
        int tempdir = dir;
        queue<pair<int,int>> q;
        q.push(make_pair(idx,tempdir));
        while (1)
        {
            if(idx == T){
                break;
            }
            idx++;
            tempdir *= -1;
            if(topni[idx-1][2]!=topni[idx][6]){
                q.push(make_pair(idx,tempdir));
            }else{
                break;
            }
        }
        idx = num;
        tempdir = dir;
        while (1)
        {
            if(idx==1){
                break;
            }
            idx--;
            tempdir *= -1;
            if(topni[idx+1][6]!=topni[idx][2]){
                q.push(make_pair(idx,tempdir));
            }else{
                break;
            }
        }
        while (!q.empty())
        {
            int cur = q.front().first;
            int rotate = q.front().second;
            q.pop();
            if(rotate==1){
                int temp = topni[cur].back();
                topni[cur].pop_back();
                topni[cur].push_front(temp);
            }else{
                int temp = topni[cur].front();
                topni[cur].pop_front();
                topni[cur].push_back(temp);
            }
        }
    }
    int result =0;
    for (int i = 1; i <= T; i++)
    {
        if(topni[i].front()==1){
            result++;
        }
    }
    cout << result;
    return 0;
}
