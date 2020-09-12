#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000 + 1;
const int INF = 9999999999;

int N, nodeIdx;
// 노드의 개수, 노드의 너비값 중위순회로 얻어지는 값 노드 인덱스
int node[MAX];
// 노드의 언급 횟수 - 1이면 루트노드가 된다.
int low[MAX];
// 
int high[MAX];
pair<int, int> tree[MAX];
//1. 트리를 입력 받을 때 pair<int, int>형 배열에 인덱스를 부모로 하고 자식들을 입력받습니다.부모가 항상 1이 아니기 때문에 입력받는 노드를 세서 한번만 입력되는 노드를 루트로 정합니다.

//2. 중위 순회 DFS를 실행합니다.이 때, 해당 높이에서 제일 좌측에 있는 노드와 제일 우측에 있는 노드를 업데이트합니다.

//3. 각 레벨을 탐색하면서 제일 긴 길이를 구하고 해당 높이와 길이를 출력합니다.

void DFS(int nodeNum, int cnt) {
	if (tree[nodeNum].first>0)
	{
		DFS(tree[nodeNum].first, cnt + 1);
	}

	low[cnt] = min(low[cnt], nodeIdx);
	high[cnt] = max(low[cnt], nodeIdx++);

	if (tree[nodeNum].second > 0)
	{
		DFS(tree[nodeNum].second, cnt + 1);
	}
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상

    cin >> N;

    for (int i = 0; i < MAX; i++)
        low[i] = INF;

    for (int i = 0; i < N; i++)
    {

        int parent, child1, child2;
        cin >> parent >> child1 >> child2;
        node[parent]++;

        if (child1 != -1)
            node[child1]++;

        tree[parent].first = child1;
        if (child2 != -1)
            node[child2]++;
        tree[parent].second = child2;
    }

    //루트 찾기

    int root;

    for (int i = 1; i <= N; i++)
        if (node[i] == 1)
            root = i;



    //DFS

    nodeIdx = 1;
    DFS(root, 1);

    //최대 길이를 구한다
    int result = high[1] - low[1] + 1;
    int level = 1;

    for (int i = 2; i <= N; i++)
    {
        int temp = high[i] - low[i] + 1;
        if (temp > result)
        {
            result = temp;
            level = i;
        }
    }

    cout << level << " " << result << "\n";
    return 0;

}
