#pragma once
#include<iostream>
#include<deque>
#include<stack>
#include"BinSearchTree.h"
#include<ctime>

using namespace std;

int main()
{
	vector<BinSearchTree*> v;
	BinSearchTree test;
	int array[] = { -15,-12,-9,0,4,5,8,100,101 };
	test.InsertFromOrderedArray(array, 0, 8);
	test.Insert(-66);
	test.Insert(-10);
	cout << test.Delete(8) << endl;
	test.Routh(v, &test);
	cout << endl << endl;
	test.MidOrder();
	cin.get();
	return 0;
}
