#include<iostream>

void swap(int* arr, int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void SelectionSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int temp = i;
		for (int j = i + 1; j < size; j++)
			if (arr[j] < arr[temp]) temp = j;
		swap(arr, i, temp);

	}
}

int main()
{
	using namespace std;
	int arr[10] = { 1,0,2,6,5,4,9,3,7,8 };
	SelectionSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	cin.get();
	return 0;
}