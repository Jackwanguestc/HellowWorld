//bool 类型 使用一个函数找出一个整形数组中的最大最小值
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace A
{
int getMaxOrMin(int *arr, int count, bool isMax)
{
	int temp = arr[0];
	for (int i = 1; i < count; i++)
	{
		if (isMax)
		{
			if (temp < arr[i])
				temp = arr[i];
		}
		else
		{
			if (temp > arr[i])
				temp = arr[i];
		}
	}
	return temp;
}
}

int main(void)
{
	int arr[4] = {0, 1, 2, 54};
	bool isMax = false;
	int count = 0;
	cout << "please enter max or min(1/0):" << endl;
	cin >> isMax;
	cout << A::getMaxOrMin(arr, 4, isMax) << endl;
	system("pause");
	return 0;
}