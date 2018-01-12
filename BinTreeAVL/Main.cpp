#include "AVLTree.h"
#include<iostream>

int main()
{
	using namespace std;
	AVLTree myAVL;
	myAVL.Insert(5)->Insert(4)->Insert(3)->Insert(4)->Insert(6);
	cin.get();
	return 0;
}