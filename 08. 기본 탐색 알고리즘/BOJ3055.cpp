#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX =51;

int R,C;
string board[MAX];
queue<pair<int,int>> water;

int visited[MAX][MAX];

int x,y,destX,destY;

pair<int,int> moveDir[4] ={{1,0},{0,1},{-1,0},{0,-1}};
void BFS(int y,int x){
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
	q.push({0,{y,x}});
	visited[y][x] = 1;
	while(!q.empty()){
		int curT = q.top().first;
		int curY = q.top().second.first;
		int curX = q.top().second.second;
		if(curX==C-1&&curY==R-1){
			cout << curT;
			return;
		}
        int wcurSize = water.size();
        for(int j=0;j<wcurSize;j++){
            int waterY = water.front().first;
			int waterX = water.front().second;
            water.pop();
			for(int k=0;k<4;k++){
				int nextY = waterY + moveDir[k].first;
				int nextX = waterX + moveDir[k].second;
				if(waterX>=0&&waterX<R&&waterY>=0&&waterY<C){
					if(board[nextY][nextX]!='X'){
                        board[nextY][nextX]='*';
                        water.push({nextY,nextX});
                    }
				}
			}
		}
		for(int i=0;i<4;i++){
			int nextY = q.top().second.first + moveDir[i].first;
			int nextX = q.top().second.second + moveDir[i].second;
			if(nextX>=0&&nextX<R&&nextY>=0&&nextY<C){
				if(board[nextY][nextX]!='*'&&board[nextY][nextX]!='X'){
					if(visited[nextY][nextX]==0){
						q.push({curT+1,{nextY,nextX}});
						visited[nextY][nextX]=1;
					}
					
				}
			}
		}
	}
	cout << "KAKTUS";
}

int main(int argc, char* argv[]) {
	cin >> R >> C;
	for(int i=0;i<C;i++){
		cin >> board[i];
	}
	for(int i=0;i<C;i++){
		for(int j=0;j<R;j++){
			if(board[i][j]=='D'){
				destY=i;
				destX=j;
			}
			if(board[i][j]=='S'){
				y=i;
				x=j;
			}
			if(board[i][j]=='*'){
				water.push(make_pair(i,j));
			}
		}
	}
    BFS(y,x);
    return 0;
    
}
