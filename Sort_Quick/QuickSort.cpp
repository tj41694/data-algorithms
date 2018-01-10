#include<iostream>

void QuickSort(int* arr, int size)
{

}

int main()
{
	using namespace std;
	int arr[10] = { 1,0,2,6,5,4,9,3,7,8 };
	QuickSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i];
	}
	cin.get();
	return 0;
} 