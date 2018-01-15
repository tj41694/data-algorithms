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
		Node* parent; //����
		int bf;			//ƽ������
	};
	struct nodetToChange
	{
		Node** ppTemp;
		int bf;
	};

	Node* root;

	Node* Find(Node*& node, int val)
	{//�ǵݹ�
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
	{//�ݹ�
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
	{//�ǵݹ�
		if (root == nullptr)
		{
			root = new Node{ val,nullptr,nullptr,nullptr,0 };
			return;
		}
		if (root->value == val)
		{
			std::cout << "ֵ�ظ�!ȡ������";
			return;
		}
		Node** ppNode = &root; //ָ��ڵ��ָ���ָ��

		std::stack<nodetToChange> nodeStack;
		while (true)//����ѭ��
		{
			if (val > (*ppNode)->value)
			{
				nodetToChange stru{ ppNode,-1 };
				nodeStack.push(stru); //ָ��ǰ�ڵ��ָ���ָ����ջ��bf���ܵĸı�ֵ��ջ
				if ((*ppNode)->right) ppNode = &(*ppNode)->right;
				else //���в���
				{
					(*ppNode)->right = new Node{ val,nullptr,nullptr,(*ppNode),0 };
					while (nodeStack.size())//����ѭ��
					{
						(*ppNode)->bf += nodeStack.top().bf; //�Ե�ǰ�ڵ�ĵ�bfֵ���м���
						if ((*ppNode)->bf == 0) return;//���bfֵΪ0��������Ե�ǰ�����߶Ȳ�����Ӱ�� ������� �˳�ѭ��
						if ((*ppNode)->bf == 2) //�������2 ����о�������ת �˳�ѭ��
						{
							RRotation(ppNode);
							return;
						}
						else if ((*ppNode)->bf == -2)//�������-2 ����о�������ת �˳�ѭ��
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
				nodeStack.push(stru); //ָ��ǰ�ڵ��ָ���ָ����ջ��bf���ܵĸı�ֵ��ջ
				if ((*ppNode)->left) ppNode = &(*ppNode)->left;
				else //���в���
				{
					(*ppNode)->left = new Node{ val,nullptr,nullptr,(*ppNode),0 };
					while (nodeStack.size())//����ڵ����
					{
						(*ppNode)->bf += nodeStack.top().bf; //�Ե�ǰ�ڵ�ĵ�bfֵ���м���
						if ((*ppNode)->bf == 0) return;//���bfֵΪ0��������Ե�ǰ�����߶Ȳ�����Ӱ�� ������� �˳�ѭ��
						if ((*ppNode)->bf == 2) //�������2 ����о�������ת �˳�ѭ��
						{
							RRotation(ppNode);
							return;
						}
						else if ((*ppNode)->bf == -2)//�������-2 ����о�������ת �˳�ѭ��
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
				std::cout << "ֵ�ظ�!ȡ������";
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
	/*����*/
	Node* Find(int val)
	{
		return Find(root, val);
	}
	/*���ӽڵ�*/
	AVLTree* Insert(int val)
	{
		Insert(root, val);
		return this;
	}
	/*ɾ���ڵ�*/
	void Delete()
	{

	}
	~AVLTree() {}
};

