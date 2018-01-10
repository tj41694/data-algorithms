#pragma once
#include<iostream>
#include<string>
#include<map>
#include"BinST.h"

using namespace std;

int main()
{
	BinST<int, int> bst;
	bst.Insert(1, 11).Insert(2, 22).Insert(0, 00).Insert(-1, -100).Insert(3, 33).Insert(5, 55).Insert(5, 66).Insert(6, 78);
	bst.MidOrder_Nonrecursive();
	bst.FloorVist();
	cout << bst.WidthOfTree() << endl << endl;
	bst.Routh();
	bst.Reverse();
	cout << endl;
	bst.Routh();
	cin.get();
	return 0;
}