#include<iostream>


void swap(int* arr, int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void Bubble(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
			if (arr[i] > arr[j]) swap(arr, i, j);
	}
}

void Bubble2(int* arr, int size)
{
	bool flag = true;
	int index = size - 1;
	for (int i = 0; i < size - 1 && flag; i++)
	{
		flag = false;
		for (int j = 0; j < index; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				flag = true;
			}
		}
		index = index - 1;
	}
}
int main()
{
	using namespace std;
	int arr[10] = { 0,1,2,6,5,4,9,3,7,8 };
	Bubble2(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i];
	}

	cin.get();

	return 0;
}