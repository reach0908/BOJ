

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;

		stack<char> result; //결과 저장용
		stack<char> temp; // 화살표 입력시 필요한 스택

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i]=='<')
			{
				//왼쪽 화살표를 입력하는 경우 result의 탑에 있는 문자를 temp에 푸쉬하고 result에서 팝합니다.
				if (!result.empty())
				{
					temp.push(result.top());
					result.pop();
				}
			}
			//오른족 화살표를 입력하는 경우 temp의 top에있는 문자를 result에 푸쉬하고 temp에서 pop합니다.
			else if (s[i] == '>')
			{
				if (!temp.empty())
				{
					result.push(temp.top());
					temp.pop();
				}
			}
			//백스페이스를 하는 경우 단순히 result에서 한번 팝합니다.
			else if (s[i] == '-')
			{
				if (!result.empty())
				{
					result.pop();
				}
			}
			//그 외에는 단순히 result값에 푸쉬
			else
			{
				result.push(s[i]);
			}
		}
		//temp에 여전히 문자들이 남아있을 수 있다. 따라서 temp에 있는 문자들을 전부 result에 push합니다.
		while (!temp.empty())
		{
			result.push(temp.top());
			temp.pop();
		}
		string answer;
		//스택은 후입선출이기때문에 거꾸로 출력을 해주어야 한다. 
		while (!result.empty())
		{
			answer += result.top();
			result.pop();
		}
		reverse(answer.begin(), answer.end());
		cout << answer << "\n";
	}
	return 0;
}