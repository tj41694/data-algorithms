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
	int tempIndex = right + 1; //���ô���Kֵ����С����λ������ͬʱ����ж��Ƿ���
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
	/*��tempIndex == right +1��˵���ұ�ȫ��С��leftֵ,��Ȼ��right���н���
	��tempIndex�������ı䣬��ôtempIndex - 1����С��left��ֵ�����ұߵ�ֵ*/
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