#include<iostream>

void swap(int* arr, int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void QuickSort(int* arr, int left, int right)
{
	int tempIndex = right + 1; //设置大于K值的最小索引位数，且同时兼具判断是否功能
	for (int i = left + 1; i < right + 1; i++)
	{
		if (tempIndex == right + 1 && arr[left] < arr[i])
			tempIndex = i;
		else if (tempIndex != right + 1 && arr[left] > arr[i])
		{
			swap(arr, i, tempIndex);
			tempIndex++;
		}
	}
	/*如tempIndex == right +1，说明右边全部小于left值,自然与right进行交换
	如tempIndex发生过改变，那么tempIndex - 1就是小于left的值中最右边的值*/
	int k = tempIndex - 1;
	swap(arr, left, k);
	if (k - 1 - left > 1)
		QuickSort(arr, left, k - 1);
	if (right - k - 1 > 1)
		QuickSort(arr, k + 1, right);
}

int main()
{
	using namespace std;
	int arr[10] = { 5,0,2,6,1,4,9,3,7,8 };
	QuickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i];
	}
	cin.get();
	return 0;
}