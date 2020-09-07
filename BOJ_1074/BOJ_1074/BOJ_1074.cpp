

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int countNum = 0;
int x, y;
bool found = false;

void zSearch(int startX, int endX, int startY, int endY) {
	int midX = (startX + endX) / 2;
	int midY = (startY + endY) / 2;
	if (midX % 2 == 1 && midY % 2 == 1)
	{
		int i = startX;
		int j = startY;
		if (x==i&&y==j)
		{
			cout << countNum;
			return;
		}
		countNum++;
		if (x == i+1 && y == j)
		{
			cout << countNum;
			return;
		}
		countNum++;
		if (x == i && y == j+1)
		{
			cout << countNum;
			return;
		}
		countNum++;
		if (x == i+1 && y == j+1)
		{
			cout << countNum;
			return;
		}
		countNum++;
		return;
	}
	else {
		zSearch(startX, midX, startY, midY);
		zSearch(midX, endX, startY, midY);
		zSearch(startX, midX, midY, endY);
		zSearch(midX, endX, midY, endY);
	}
}

int main()
{
	cin >> N >> y >> x;
	//벡터 초기화
	int rowcol = pow(2, N);
	zSearch(0, rowcol, 0, rowcol);
}