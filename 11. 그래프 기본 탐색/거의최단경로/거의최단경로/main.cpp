//
//  main.cpp
//  거의최단경로
//
//  Created by KJH on 2020/09/16.
//  Copyright © 2020 KJH. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define INF 1e9

using namespace std;

const int MAX=500;

int N,M;
vector<pair<int, int>>  graph[MAX];
//최단 거리에 해당하는 정점을 트레이스에 저장
vector<pair<int, int>> trace[MAX];
bool visited[MAX][MAX];

vector<int> dijkstra(int start, int vertex){
    vector<int> distance(vertex,INF); // 스타트를 기준으로 거리
    distance[start] = 0; // 자기 자신까지는 0
    
    priority_queue<pair<int, int>> pq; //cost , vertex
    pq.push(make_pair(0, start)); //초기비용과 시작점
    while (!pq.empty()) {
        int cost = -pq.top().first; //거리의 부호를 바꾸어 작은 정점부터 꺼낼수있도록
        int curVetex = pq.top().second;
        pq.pop();
        
        //최소거리를 원한다
        if (distance[curVetex]<cost) {
            continue;
        }
        //이웃들을 확인하는 과정
        for (int i=0; i<graph[curVetex].size(); i++) {
            int neighbor = graph[curVetex][i].first;
            int neighborDistance = cost + graph[curVetex][i].second;
            
            //삭제된 정점간의 간선 무시
            if (graph[curVetex][i].second==-1) {
                continue;
            }
            //최소경로 발견 시 업데이트
            if(distance[neighbor]>neighborDistance){
                distance[neighbor] = neighborDistance;
                pq.push(make_pair(-neighborDistance, neighbor));
                //트레이스 갱신
                trace[neighbor].clear();
                trace[neighbor].push_back(make_pair(curVetex,neighborDistance));
                
            }
            //최단거리 찾을 때마다 트레이스 갱신
            else if(distance[neighbor]==neighborDistance){
                trace[neighbor].push_back(make_pair(curVetex, neighborDistance));
                
            }
            
        }
    }
    return distance;
}

void BFS(int destination){
    //큐를 이용하여 trace에 해당하는 정점들을 지울 준비
    queue<int> q;
    
    q.push(destination);
    
    while (!q.empty()) {
        int curVertex = q.front();
        q.pop();
        for (int i=0; i<trace[curVertex].size(); i++) {
            int neighbor = trace[curVertex][i].first;
            if (visited[curVertex][neighbor]) {
                continue;
            }
            
            //원래 BFS에는 없는 구조,
            //원레 정점간 연결이 1->2 라면 trace에는 2->1로 연결되어 있기에
            //graph[curVertex][]가 아닌 graph[neighbor][]로 봐야한다
            //처음 들어오는 curVertex이 도착점임을 생각하면 쉽다


            for (int j=0; j<graph[neighbor].size(); j++) {
                if (graph[neighbor][j].first==curVertex) {
                    graph[neighbor][i].second=-1;
                }
            }
            q.push(neighbor);
        }
        
    }
    
}

int main(){
   
    while (1) {
        memset(visited, false, sizeof(visited));
        memset(trace, 0, sizeof(trace));
        for (int i=0; i<MAX; i++) {
            graph[i].clear();
        }
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        int S,D;
        cin >> S >> D;
        for (int i=0; i<M; i++) {
            int source, destination, cost;
            cin >> source >> destination >> cost;
            graph[source].push_back(make_pair(destination, cost));

        }
        dijkstra(S, N);
        BFS(D);
        vector<int> result = dijkstra(S, N);
        if (result[D]==INF) {
            cout << -1 << endl;
        }else{
            cout << result[D] << endl;
        }
    }
    return 0;
}



