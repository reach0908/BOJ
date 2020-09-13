// BOJ_1991.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

const int MAX = 26;

using namespace std;

int T;
vector < pair<int, bool >> Tree[MAX]; //(벡터로 된 배열)

void preorder(int node) {
	cout << (char)(node + 'A');
	for (int i = 0; i < Tree[node].size(); i++)
	{
		preorder(Tree[node][i].first);
	}
}

void inorder(int node) {
	//자식이 존재하고 왼쪽자식이라면
	if (Tree[node].size()&&Tree[node][0].second)
	{
		inorder(Tree[node][0].first);
	}
	cout << (char)(node + 'A');

	//오른쪽자식만있다면
	if (Tree[node].size() && !Tree[node][0].second) {
		inorder(Tree[node][0].first);
	}
	else if (Tree[node].size() == 2) {
		inorder(Tree[node][1].first);
	}
}

void postorder(int node) {
	for (int i = 0; i < Tree[node].size(); i++)
	{
		postorder(Tree[node][i].first);
	}
	cout << (char)(node + 'A');
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		char a,b,c;
		cin >> a >> b >> c;

		//왼쪽자식 넣기
		if (b!='.')
		{
			Tree[a - 'A'].push_back({ b - 'A',true });
		}
		if (c!='.')
		{
			Tree[a - 'A'].push_back({ c - 'A',false });
		}
	}
	preorder(0);

	cout << "\n";

	inorder(0);

	cout << "\n";

	postorder(0);

	cout << "\n";

	return 0;


}
