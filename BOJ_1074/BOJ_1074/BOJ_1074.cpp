

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int countNum = 0;
int x, y;
bool found = false;

void zSearch(int startX, int endX, int startY, int endY) {
	if (found) {
		return;
	}
	int midX = (startX + endX) / 2;
	int midY = (startY + endY) / 2;
	if (midX % 2 == 1&&midY % 2 == 1)
	{
		for (int i = startY; i < endY; i++)
		{
			for (int j = startX; j < endX; j++) {
				if (i == x && j == y)
				{
					found = true;
					return;
				}
				countNum++;
			}
		}
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
	cin >> N >> x >> y;
	//벡터 초기화
	int rowcol = pow(2, N);
	zSearch(0, rowcol, 0, rowcol);
	cout << countNum;
	return 0;
}

