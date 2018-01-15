#include "AVLTree.h"
#include<iostream>

int main()
{
	using namespace std;
	AVLTree myAVL;
	myAVL.Insert(50)->Insert(1)->Insert(99)->Insert(86);
	unsigned int n;
	while (cin >> n)
	{
		myAVL.Insert(n);
	}
	cin.get();
	return 0;
}