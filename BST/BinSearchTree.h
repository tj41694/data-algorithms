#pragma once
#include<iostream>
#include<stack>
#include<deque>
#include<vector>

using namespace std;

/*
����������
�ص�1������ÿһ���ڵ�����ֵһ��������������ֵ��С���Һ���ֵ��
�ص�2��������������һ���������С�
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

	/*@���ӽڵ�*/
	BinSearchTree* Insert(int value1);

	/*@�������*/
	BinSearchTree* Max();

	/*@������С*/
	BinSearchTree* Min();

	/*@����ָ��ֵ*/
	BinSearchTree* Find(int data);

	/*@ɾ��ָ��ֵ*/
	BinSearchTree* Delete(int data);

	/*@ǰ�����*/
	void PreOrder(const BinSearchTree* root);

	/*@ǰ�����*/
	void PreOrder();

	/*@�������*/
	void MidOrder(const BinSearchTree* root);

	/*@�������*/
	void MidOrder();

	/*@����������ǵݹ飩*/
	void MidOrder_Nonrecursive();

	/*@������*/
	void FloorVist();

	/*@�ڵ����*/
	int NumOfTree();

	/*@�ڵ����*/
	int NumOfTree(BinSearchTree*);

	/*@�ڵ����*/
	int DepthOfTree();

	/*@�ڵ����*/
	int DepthOfTree(BinSearchTree*);

	/*@�������Ŀ��*/
	int Width(int& width);

	/*@����Ҷ�ӵ���·��*/
	void Routh(vector<BinSearchTree*>& vec, BinSearchTree* root);

	/*@�ж��������Ƿ���ͬ*/
	static bool JudeSame(BinSearchTree* first, BinSearchTree* second);

	/*@����������*/
	 void Reverse(BinSearchTree* root);

	 /*@��һ���������鹹��һ����Ч��ƽ�������*/
	 void InsertFromOrderedArray(const int* array, int start, int end);
	 /*@��һ���������鹹��һ����Ч��ƽ�������*/
	 void InsertFromOrderedArray(BinSearchTree*& root, const int* array, int start, int end);
	~BinSearchTree();
};

