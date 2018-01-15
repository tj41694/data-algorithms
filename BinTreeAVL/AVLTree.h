#pragma once
#include<iostream>
#include<stack>

class AVLTree
{
private:
	struct Node
	{
		int value;
		Node* left;
		Node* right;
		Node* parent; //备用
		int bf;			//平衡因子
	};
	struct nodetToChange
	{
		Node** ppTemp;
		int bf;
	};

	Node* root;

	Node* Find(Node*& node, int val)
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

	void Insert(Node*& root, int val)
	{//非递归
		if (root == nullptr)
		{
			root = new Node{ val,nullptr,nullptr,nullptr,0 };
			return;
		}
		if (root->value == val)
		{
			std::cout << "值重复!取消插入";
			return;
		}
		Node** ppNode = &root; //指向节点的指针的指针

		std::stack<nodetToChange> nodeStack;
		while (true)//查找循环
		{
			if (val > (*ppNode)->value)
			{
				nodetToChange stru{ ppNode,-1 };
				nodeStack.push(stru); //指向当前节点的指针的指针入栈、bf可能的改变值入栈
				if ((*ppNode)->right) ppNode = &(*ppNode)->right;
				else //进行插入
				{
					(*ppNode)->right = new Node{ val,nullptr,nullptr,(*ppNode),0 };
					while (nodeStack.size())//回溯循环
					{
						(*ppNode)->bf += nodeStack.top().bf; //对当前节点的的bf值经行计算
						if ((*ppNode)->bf == 0) return;//如果bf值为0，则表明对当前子树高度不产生影响 插入完成 退出循环
						if ((*ppNode)->bf == 2) //如果等于2 则进行经行右旋转 退出循环
						{
							RRotation(ppNode);
							return;
						}
						else if ((*ppNode)->bf == -2)//如果等于-2 则进行经行左旋转 退出循环
						{
							LRotation(ppNode);
							return;
						}
						nodeStack.pop();
						if (nodeStack.size() == 0) return;
						ppNode = nodeStack.top().ppTemp;
					}
					return;
				}
			}
			else if (val < (*ppNode)->value)
			{
				nodetToChange stru{ ppNode,1 };
				nodeStack.push(stru); //指向当前节点的指针的指针入栈、bf可能的改变值入栈
				if ((*ppNode)->left) ppNode = &(*ppNode)->left;
				else //进行插入
				{
					(*ppNode)->left = new Node{ val,nullptr,nullptr,(*ppNode),0 };
					while (nodeStack.size())//向根节点回溯
					{
						(*ppNode)->bf += nodeStack.top().bf; //对当前节点的的bf值经行计算
						if ((*ppNode)->bf == 0) return;//如果bf值为0，则表明对当前子树高度不产生影响 插入完成 退出循环
						if ((*ppNode)->bf == 2) //如果等于2 则进行经行右旋转 退出循环
						{
							RRotation(ppNode);
							return;
						}
						else if ((*ppNode)->bf == -2)//如果等于-2 则进行经行左旋转 退出循环
						{
							LRotation(ppNode);
							return;
						}
						nodeStack.pop();
						if (nodeStack.size() == 0) return;
						ppNode = nodeStack.top().ppTemp;
					}
					return;
				}
			}
			else if (val == (*ppNode)->value)
			{
				std::cout << "值重复!取消插入";
				return;
			}
		}
	}

	void RRotation(Node** node)
	{
		if ((*node)->left->bf < 0) LRot((*node)->left);
		RRot(*node);
	}

	void LRotation(Node** node)
	{
		if ((*node)->right->bf > 0) RRot((*node)->right);
		LRot(*node);
	}

	void RRot(Node* &node)
	{
		Node* leftChild = node->left;
		if (node->bf == 2)
		{
			node->bf = 0;
			leftChild->bf = 0;
		}
		else if (node->bf == 1)
		{
			leftChild->bf = -1;
			if (node->left->bf == 1) node->bf = -1;
			else node->bf = 0;
		}
		node->left = leftChild->right;
		leftChild->right = node;
		node = leftChild;
	}

	void LRot(Node* &node)
	{
		Node* rightChild = node->right;
		if (node->bf == -2)
		{
			node->bf = 0;
			rightChild->bf = 0;
		}
		else if (node->bf == -1)
		{
			rightChild->bf = 1;
			if (node->right->bf == -1) node->bf = 1;
			else node->bf = 0;
		}
		node->right = rightChild->left;
		rightChild->left = node;
		node = rightChild;
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

