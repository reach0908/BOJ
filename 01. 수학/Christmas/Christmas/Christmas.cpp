
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//부분합을 이용한 크리스마스 인형문제
//종만북 17.2


//D[]의 부분합 배열 psum[]과 k가 주어질 때, 몇가지 방법으로 살 수 있는지 반환한다.
//psum[]의 첫번째 원소 전에 0을 삽입했다고 가정한다.
vector<int> partialSum(const vector<int>& a) {
    vector<int> ret(a.size());
    ret[0] = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        ret[i] = ret[i - 1] + a[i];
    }
    return ret;
}
int rangeSum(const vector<int>& psum, int a, int b) {
    if (a == 0) return psum[b];
    return psum[b] - psum[a - 1];
}


int waysToBuy(const vector<int>& psum, int k) {
    const int MOD = 20091101;
    int ret = 0;
    //psum의 각 값을 몇 번이나 본 적 있는지 기록한다.
    vector<long long> count(k, 0);
    for (int i = 0; i < psum.size(); i++)
    {
        count[psum[i]]++;
    }
    //두번 이상 본 적 있다면 이 값중 두개를 선택하는 방법의 수를 더한다.
    for (int i = 0; i < k; i++)
    {
        if (count[i] >= 2) {
            ret = (ret + (count[i] * (count[i] - 1)) / 2)) % MOD;
        }
    }
    return ret;
}

int maxBuys(const vector<int>& psum, int k) {
    //ret[i]=첫번째 상자부터 i번째 상자까지 고려했을 때 살 수 있는 최대 개수
    vector<int> ret(psum.size(),0);
    //prev[s] = psum[]이 s였던 마지막 위치
    vector<int> prev(k, -1);
    for (int  i = 0; i < psum.size(); i++)
    {
        //i번째 상자를 고려하지 않은 경우
        if (i > 0) {
            ret[i] = ret[i - 1];
        }
        else
        {
            ret[i] = 0;
        }
        //psum[i]를 전에도 본 적이 있으면, prev[psum[i]]+1부터 여기까지 쭉 사본다.
        int loc = prev[psum[i]];
        if (loc != i) {
            ret[i] = max(let[i], ret[loc] + 1);
        }
        prev[psum[i]];
    }
   

    
}

int main()
{
    std::cout << "Hello World!\n";
}
