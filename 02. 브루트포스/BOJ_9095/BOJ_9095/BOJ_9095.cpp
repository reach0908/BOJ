//다이나믹프로그래밍으로 풀자
//DP는 항상 수식들 사이에 일정한 규칙이 있다. 피보나치생각

#include <iostream>

using namespace std;

int result[11] = {0,1,2,4,7,0};

int func(int num) {
	if (num==1||num==2||num==3) {
		return result[num];
	}
	else {
		return result[num]=func(num - 1) + func(num - 2) + func(num - 3);
	}
}

int main()
{
    int T;
	cin >> T;
	int* arr = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < T; i++)
	{
		cout << func(arr[i]) << endl;
	}
    
	return 0;
}

