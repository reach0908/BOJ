#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX =50;

int R,C;
string board[MAX];

int cache[MAX][MAX]={0};

int x,y,destX,destY;

pair<int,int> moveDir[4] ={{1,0},{0,1},{-1,0},{0,-1}};
queue<pair<int,int>> wq;
void BFS(int y,int x){
	
	queue<pair<int,int>> q;
    
    q.push({y,x});
	cache[y][x] = 1;
	while(!q.empty()){
		int curY = q.front().first;
		int curX = q.front().second;
		if(curY==destY&&curX==destX){
			cout << cache[curY][curX]-1;
		}
		q.pop();
		for(int i=0;i<wq.size();i++){
			int curWY = wq.front().first;
			int curWX = wq.front().second;
			wq.pop();
			for(int j=0;j<4;j++){
				int nextWX = curWX + moveDir[j].second;
				int nextWY = curWY + moveDir[j].first;
                if(0<=nextWY&&nextWY<R&&0<=nextWX&&nextWX<C){
				    if(board[nextWY][nextWX]=='.'){
				    	wq.push({nextWY,nextWX});
			    		board[nextWY][nextWX]='*';
			    	}
                }
			}
		}
		for(int i=0;i<q.size();i++){
			for(int j=0;j<4;j++){
				int nextY = curY + moveDir[j].first;
				int nextX = curX + moveDir[j].second;
                if(0<=nextX&&nextX<C&&0<=nextY&&nextY<R){
                    if(board[nextY][nextX]!='X'&&board[nextY][nextX]!='*'){
					    if(cache[nextY][nextX]==0){
						    cache[nextY][nextX] = cache[curY][curX]+1;
						    q.push({nextY,nextX});
					    }
				    }
                }
			}
		}
	}
	cout << "KAKTUS";
}

int main() {
	cin >> R >> C;
	for(int i=0;i<R;i++){
		cin >> board[i];
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(board[i][j]=='D'){
				destY=i;
				destX=j;
			}
			if(board[i][j]=='S'){
				y=i;
				x=j;
			}
			if(board[i][j]=='*'){
				wq.push(make_pair(i,j));
			}
		}
	}
	BFS(y,x);

	return 0;
}
