#pragma once
#include<iostream>

class AVLTree
{
private:
	struct Node
	{
		int value;
		Node* left;
		Node* right;
		int bf;			//平衡因子
	};
	Node* root;

	Node* Find(Node* node, int val)
	{//非递归
		if (node == nullptr) return nullptr;
		Node* temp = node;
		if (temp->value == val) return node;
		while (temp->value != val)
		{
			if (val > temp->value)
			{
				if (temp->right) temp = temp->right;
				else return nullptr;
			}
			else
			{
				if (temp->left) temp = temp->left;
				else return nullptr;
			}
		}
		return temp;
	}

	Node* Find2(Node* node, int val)
	{//递归
		if (node == nullptr) return nullptr;
		if (node->value == val) return node;
		else if (node->value > val)
		{
			if (node->left) return Find(node->left, val);
			else return nullptr;
		}
		else
		{
			if (node->right) return Find(node->right, val);
			else return nullptr;
		}
	}

	void Insert(Node*& node, int val)
	{//非递归
		if (node == nullptr)
		{
			node = new Node{ val,nullptr,nullptr,0 };
			return;
		}
		if (node->value == val)
		{
			std::cout << "值重复!取消插入";
			return;
		}
		Node* pTemp = node;
		while (true)
		{
			if (val > pTemp->value)
			{
				if (pTemp->right == nullptr)
				{
					pTemp->right = new Node { val,nullptr,nullptr,0 };
					return;
				}
				else pTemp = pTemp->right;
			}
			else if (val < pTemp->value)
			{
				if (pTemp->left == nullptr)
				{
					pTemp->left = new Node{ val,nullptr,nullptr,0 };
					return;
				}
				else pTemp = pTemp->left;
			}
			else if(val == pTemp->value)
			{
				std::cout << "值重复!取消插入";
				return;
			}
		}

	}

	void Insert2(Node*& node, int val)
	{//递归
		if (node == nullptr)
		{
			node = new Node{ val,nullptr,nullptr,0 };
			return;
		}
		if		(val > node->value) Insert2(node->right, val);
		else if (val < node->value) Insert2(node->left, val);
		else std::cout << "值重复!取消插入";
	}

	void LRot(Node* node)
	{

	}

	void RRot(Node* node)
	{

	}
public:
	AVLTree() { root = nullptr; }
	/*查找*/
	Node* Find(int val)
	{
		return Find(root, val);
	}
	/*增加节点*/
	AVLTree* Insert(int val)
	{
		Insert(root, val);
		return this;
	}
	/*删除节点*/
	void Delete()
	{

	}
	~AVLTree() {}
};

