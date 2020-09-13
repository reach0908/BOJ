// BOJ_1543.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

string s;
string target;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);
    getline(cin, target);

    if (target.size() > s.size()) {
        cout << 0 << "\n";
    }
    else {
        int result = 0;
        for (int i = 0; i < s.size()-target.size()+1; i++)
        {
            bool same = true;
            for (int j = 0;  j < target.size();  j++)
            {
                if (s[i+j]!=target[j])
                {
                    same = false;
                    break;

                }
            }
            if (same) {
                result++;
                i += target.size() - 1;
            }
        }
        cout << result << "\n";
    }
    return 0;
}


//겟 라인의 함수 사용과 글자의 맞음을 비교할때
//맞은 것을 늘려나가는 것보다 틀렸을 때 바로 break해버리는것이 빠르다.