
#include <iostream>
#include <cstdlib>

using namespace std;

int startX, startY, endX, endY;

int main()
{
	cin >> startX >> startY >> endX >> endY;
	int distX, distY;
	distX = abs(endX - startX);
	distY = abs(endY - startY);
	if (distX==0&&distY==0)
	{
		cout << "DOT";
	}
	else {
		if ((distX>0&&distY==0)||(distX==0&&distY>0))
		{
			cout << "SEGMENT";
		}
		if (distX>0&&distY>0) {
			if (distX==distY)
			{
				cout << "SQUARE";
			}
			else {
				cout << "RECTANGLE";
			}
		
		}
	}
	return 0;
}

