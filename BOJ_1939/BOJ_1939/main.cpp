//
//  main.cpp
//  BOJ_1939
//
//  Created by KJH on 2020/09/12.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 100000 + 1;
int N, M;
int start, finish;
vector<pair<int, int>> graph[MAX];
bool visited[MAX];

bool BFS(int cost){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current==finish) {
            return true;
        }
        for (int i=0; i<graph[current].size(); i++) {
            int next =graph[current][i].first;
            int nextCost = graph[current][i].second;
            if (!visited[next]&&cost<=nextCost) {
                visited[next]=true;
                q.push(next);
            }
        }
    }
    
    return false;
}

int main(void)

{

        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin 실행속도 향상
        cin >> N >> M;

        int maxCost = 0;

        for (int i = 0; i < M; i++)
        {
                 int factory1, factory2, cost;
                 cin >> factory1 >> factory2 >> cost;

                 //양방향 그래프
                 graph[factory1].push_back(make_pair(factory2, cost));
                 graph[factory2].push_back(make_pair(factory1, cost));
                 maxCost = max(maxCost, cost); //최대 중량 업데이트
        }
        cin >> start >> finish;

        //이진 탐색
        int low = 0, high = maxCost;
        while (low <= high)
        {
            //초기화 함수, 방문을 전부 false로 초기화
                 memset(visited, false, sizeof(visited));
                 int mid = (low + high) / 2;
                 if (BFS(mid))
                         low = mid + 1; // 성공하면 최대중량 늘려보기
                 else
                         high = mid - 1; // 실패하면 최대중량 내리기
            //중량은 정해져있는게 아니라 1~ 범위의 자연수이기때문에 이렇게 내려도 된다.
        }
        cout << high << "\n";
        return 0;

}



//이진탐색은 찾고자하는 값에 이진탐색을 씌워야한다
//문제에서는 중량이 10억이다. 이를 1초에 구현하지못하므로
//중량에 로그나 루트를 씌워 시간을 단축시켜야한다.

//BFS 사용

