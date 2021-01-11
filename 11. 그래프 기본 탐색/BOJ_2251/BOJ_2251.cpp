#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 200;

int A,B,C;
bool visited[MAX][MAX][MAX]={false};

vector<int> v;

typedef struct options
{
    int a;
    int b;
    int c;
}options;

void BFS(){
    queue<options> q;
    options op = {0,0,C};
    q.push(op);

    while (!q.empty())
    {
        int curA = q.front().a;
        int curB = q.front().b;
        int curC = q.front().c;

        int leftA = A - curA;
        int leftB = B - curB;
        int leftC = C - curC;

        q.pop();

        if(visited[curA][curB][curC]){
            continue;
        }
        visited[curA][curB][curC] = true;
        if (curA==0)
        {
            v.push_back(curC);
        }

        //a->b
        if (leftB > curA)
        {
            q.push({0, curB+curA, curC});
        }
        else
        {
            q.push({curA-leftB, B, curC});
        }
        //a->c
        if (leftC > curA)
        {
            q.push({0, curB, curC+curA});
        }
        else
        {
            q.push({curA-leftC, curB, C});
        }
        //b->c
        if (leftC > curB)
        {
            q.push({curA, 0, curC+curB});
        }
        else
        {
            q.push({curA, curB-leftC, C});
        }
        //c-a
        if (leftA > curC)
        {
            q.push({curA+curC, curB, 0});
        }
        else
        {
            q.push({A, curB, curC-leftA});
        }
        //c-b
        if (leftB > curC)
        {
            q.push({curA, curB+curC, 0});
        }
        else
        {
            q.push({curA, B, curC-leftB});
        }
        //b-a
        if (leftA > curB)
        {
            q.push({curA+curB, 0, curC});
        }
        else
        {
            q.push({A, curB - leftA, curC});
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> A >> B >> C;
    BFS();
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
