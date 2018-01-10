#pragma once
#include<iostream>
#include<stack>
#include<deque>
#include<vector>

using namespace std;

/*
二叉搜索树
特点1：对于每一个节点它的值一定大于它的左孩子值，小于右孩子值。
特点2：中序遍历结果是一个有序序列。
*/
class BinSearchTree
{
private:
	unsigned int count;

public:
	int value;
	BinSearchTree* right;
	BinSearchTree* left;

public:
	BinSearchTree();
	BinSearchTree(int);
	BinSearchTree(const BinSearchTree&);

	unsigned int Length();

	/*@增加节点*/
	BinSearchTree* Insert(int value1);

	/*@查找最大*/
	BinSearchTree* Max();

	/*@查找最小*/
	BinSearchTree* Min();

	/*@查找指定值*/
	BinSearchTree* Find(int data);

	/*@删除指定值*/
	BinSearchTree* Delete(int data);

	/*@前序遍历*/
	void PreOrder(const BinSearchTree* root);

	/*@前序遍历*/
	void PreOrder();

	/*@中序遍历*/
	void MidOrder(const BinSearchTree* root);

	/*@中序遍历*/
	void MidOrder();

	/*@中序遍历（非递归）*/
	void MidOrder_Nonrecursive();

	/*@逐层遍历*/
	void FloorVist();

	/*@节点个数*/
	int NumOfTree();

	/*@节点个数*/
	int NumOfTree(BinSearchTree*);

	/*@节点深度*/
	int DepthOfTree();

	/*@节点深度*/
	int DepthOfTree(BinSearchTree*);

	/*@二叉树的宽度*/
	int Width(int& width);

	/*@所有叶子到根路径*/
	void Routh(vector<BinSearchTree*>& vec, BinSearchTree* root);

	/*@判断两棵树是否相同*/
	static bool JudeSame(BinSearchTree* first, BinSearchTree* second);

	/*@二叉树镜像*/
	 void Reverse(BinSearchTree* root);

	 /*@将一个有序数组构造一个高效的平衡二叉树*/
	 void InsertFromOrderedArray(const int* array, int start, int end);
	 /*@将一个有序数组构造一个高效的平衡二叉树*/
	 void InsertFromOrderedArray(BinSearchTree*& root, const int* array, int start, int end);
	~BinSearchTree();
};

