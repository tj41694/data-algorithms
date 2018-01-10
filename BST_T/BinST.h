#pragma once
#include<stack>
#include<deque>
#include<vector>

using namespace std;

template <typename Tkey, typename Tvalue>
class BinST
{

private:
	struct Node
	{
		Tkey key;
		Tvalue value;
		Node* left;
		Node* right;
	};
	unsigned int count = 0;
	unsigned int cancelN = 0;
	unsigned int width = 0;
	vector<Node*> routh;

	BinST<Tkey, Tvalue>& Insert(Tkey k, Tvalue v, Node*& node);

	Node* FindMax(Node* node) const
	{
		if (node->right)
			return FindMax(node->right);
		else
			return node;
	}

	Node* FindMin(Node* node) const
	{
		if (node == nullptr)
			return nullptr;
		if (node->left)
			return FindMin(node->left);
		else
			return node;
	}

	void MidOrder(Node* node)
	{
		if (node == nullptr)
			return;
		MidOrder(node->left);
		cout << node->key << "(" << node->value << ")" << " ";
		MidOrder(node->right);
	}

	void MidOrder_Nonrecursive(Node* node)
	{
		if (node == nullptr)
			return;
		stack<Node*> s;
		Node* temp = node;
		while (s.size() || temp != nullptr)
		{
			if (temp != nullptr)
			{
				s.push(temp);
				temp = temp->left;
			}
			else
			{
				temp = s.top();
				s.pop();
				cout << temp->key << "(" << temp->value << ")" << " ";
				temp = temp->right;
			}
		}
	}

	Node* Find(Node* node, Tkey k) const
	{
		if (node == nullptr)
			return nullptr;
		if (k == node->key)
			return node;
		else if (k > node->key)
			Find(node->right, k);
		else
		{
			Find(node->left, k);
		}
	}

	int Num(Node* node)
	{
		if (node)
			return Num(node->left) + Num(node->right) + 1;
		else
			return 0;
	}

	int Depth(Node* node)
	{
		if (node == nullptr)
			return 0;
		int l = Depth(node->left);
		int r = Depth(node->right);
		return (l > r ? l : r) + 1;
	}

	unsigned int Width(Node* node)
	{
		if (node == nullptr)
			return 0;
		deque<Node*> dequ;
		dequ.push_back(node);
		Node* current;
		unsigned int temWidth;
		temWidth = dequ.size();
		width = 0;
		while (temWidth)
		{
			if (temWidth > width)
				width = temWidth;
			while (temWidth)
			{
				current = dequ.front();
				dequ.pop_front();
				if (current->left)
					dequ.push_back(current->left);
				if (current->right)
					dequ.push_back(current->right);
				temWidth--;
			}
			temWidth = dequ.size();
		}
		return width;
	}

	void Routh(Node* node)
	{
		if (node == nullptr)
			return;
		routh.push_back(node);
		if (node->left == nullptr && node->right == nullptr)
		{
			vector<Node*>::iterator itr = routh.begin();
			for (; itr != routh.end(); itr++)
				cout << (*itr)->key << "(" << (*itr)->value << ")" << endl;
			cout << "-----" << endl;
		}
		Routh(node->left);
		Routh(node->right);
		routh.pop_back();
	}

	void ReverseTree(Node* node)
	{
		if (node == nullptr)
			return;
		Node* temp;
		if (node->left == nullptr && node -> right == nullptr)
			return;
		temp = node->left;
		node->left = node -> right;
		node->right = temp;
		ReverseTree(node->left);
		ReverseTree(node->right);
	}
public:

	Node* root;

	/*���캯��*/
	BinST();

	/*���캯��*/
	BinST(Tkey k, Tvalue v);

	/*����ڵ�*/
	BinST<Tkey, Tvalue>& Insert(Tkey k, Tvalue v);

	/*�������*/
	Node* FindMax() const
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->right)
			return FindMax(root->right);
		else
			return root;
	}

	/*������С*/
	Node* FindMin() const
	{
		return FindMin(root);
	}

	/*����ֵ����*/
	Node* Find(Tkey k) const
	{
		return Find(root, k);
	}

	/*�������*/
	void MidOrder()
	{
		MidOrder(root);
		cout << endl;
	}

	/*�ǵݹ��������*/
	void MidOrder_Nonrecursive()
	{
		MidOrder_Nonrecursive(root);
		cout << endl;
	}

	/*@������*/
	void FloorVist()
	{
		if (root == nullptr)
			return;
		deque<Node*> dequ;
		dequ.push_back(root);
		Node* current = nullptr;
		while (dequ.size())
		{
			current = dequ.front();
			dequ.pop_front();
			cout << current->key << "(" << current->value << ")" << " ";
			if (current->left != nullptr)
				dequ.push_back(current->left);
			if (current->right != nullptr)
				dequ.push_back(current->right);
		}
		cout << endl;
	}

	/*�ڵ���*/
	int NumOfTree()
	{
		cout << count << endl;
		return Num(root);
	}

	/*���߶�*/
	int DepthOfTree()
	{
		int n = Depth(root);
		cout << n << endl;
		return n;
	}

	/*@�������Ŀ��*/
	unsigned int WidthOfTree()
	{
		return Width(root);
	}

	/*@����Ҷ�ӵ���·��*/
	void Routh()
	{
		Routh(root);
	}

	/*@���������*/
	void Reverse()
	{
		ReverseTree(root);
	}


	/*��������*/
	~BinST();
};

template<typename Tkey, typename Tvalue>
inline BinST<Tkey, Tvalue>::BinST()
{
	cout << "���캯��1" << endl;
	if (root != nullptr)
	{
		delete root;
	}
	root = nullptr;
	count = 0;
}

template<typename Tkey, typename Tvalue>
inline BinST<Tkey, Tvalue>::BinST(Tkey k, Tvalue v)
{
	cout << "���캯��2" << endl;
	if (root != nullptr)
	{
		delete root;
	}
	root = new Node;
	root->key = k;
	root->value = v;
	root->left = nullptr;
	root->right = nullptr;
	count = 1;
}

template<typename Tkey, typename Tvalue>
inline BinST<Tkey, Tvalue>& BinST<Tkey, Tvalue>::Insert(Tkey k, Tvalue v)
{
	if (root == nullptr)
	{
		root = new Node;
		root->key = k;
		root->value = v;
		root->left = nullptr;
		root->right = nullptr;
		count += 1;
		return *this;
	}
	if (k > root->key)
	{
		Insert(k, v, root->right);
	}
	else if (k < root->key)
	{
		Insert(k, v, root->left);
	}
	else
	{
		cout << "�ظ���ֵ��ȡ�����룺 " << ++cancelN << " ��" << endl;
		return *this;
	}
}

template<typename Tkey, typename Tvalue>
inline BinST<Tkey, Tvalue>& BinST<Tkey, Tvalue>::Insert(Tkey k, Tvalue v, Node*& node)
{
	if (node == nullptr)
	{
		node = new Node;
		node->key = k;
		node->value = v;
		node->left = nullptr;
		node->right = nullptr;
		count += 1;
		return *this;
	}
	if (k > node->key)
	{
		Insert(k, v, node->right);
	}
	else if (k < node->key)
	{
		Insert(k, v, node->left);
	}
	else
	{
		cout << "�ظ���ֵ��ȡ�����룺 " << ++cancelN << " ��" << endl;
		return *this;
	}
}

template<typename Tkey, typename Tvalue>
inline BinST<Tkey, Tvalue>::~BinST()
{
}
