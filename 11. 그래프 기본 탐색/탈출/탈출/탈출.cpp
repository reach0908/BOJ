

#include <iostream>

using namespace std;

const int MAX = 50;

int R, C;
char board[MAX][MAX];

int startY, startX;
int destY, destX;
int waterY, waterX;

int BFS() {




	return -1;
}

int main()
{
	cin >> R >> C;  

	for (int i = 0; i < R; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < C; j++) {
			board[i][j] = temp[j];
			if (temp[j]=='D')
			{
				startX = j;
				startY = i;
			}
			if (temp[j] == 'S')
			{
				destX = j;
				destY = i;
			}
			if (temp[j] == '*')
			{
				waterX = j;
				waterY = i;`
			}

		}
	}
	int result = BFS();
	if (result==-1)
	{
		cout << "KAKTUS";
	}
	else {
		cout << result;
	}
	return 0;

}

