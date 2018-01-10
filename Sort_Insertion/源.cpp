#include<iostream>

void swap(int* arr, int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void InsertionSort(int* arr, int size)
{
	int temp;
	for (int i = 1; i < size; i++)
	{
		temp = arr[i];
		for (int j = i - 1; j >= 0; j--)
			if (arr[j] > temp) swap(arr, j, j + 1);
	}
}

int main()
{
	using namespace std;
	int arr[10] = { 1,0,2,6,5,4,9,3,7,8 };
	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i];
	}
	cin.get();
	return 0;
}