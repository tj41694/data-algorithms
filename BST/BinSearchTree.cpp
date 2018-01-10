#include "BinSearchTree.h"



BinSearchTree::BinSearchTree()
{
	value = 0;
	count = 0;
	right = nullptr;
	left = nullptr;
}

BinSearchTree::BinSearchTree(int value1)
{
	value = value1;
	count = 1;
	right = nullptr;
	left = nullptr;
}

BinSearchTree::BinSearchTree(const BinSearchTree &)
{

}

unsigned int BinSearchTree::Length()
{
	return count;
}

BinSearchTree* BinSearchTree::Insert(int value1)
{
	if (count == 0)
	{//树为空时将值赋予根节点
		count++;
		value = value1;
	}
	else
	{//树不为空时new一个节点，并找到合适的位置插入
		count++;
		BinSearchTree* newNode = new BinSearchTree(value1);
		BinSearchTree* parent = this;
		while (parent != nullptr)
		{
			if (parent->value < value1)
			{
				if (parent->right == nullptr)
					break;
				else
					parent = parent->right;
			}
			else
			{
				if (parent->left == nullptr)
					break;
				else
					parent = parent->left;
			}
		}
		if (parent->value < value1)
			parent->right = newNode;
		else
			parent->left = newNode;
	}
	return this;
}

BinSearchTree * BinSearchTree::Max()
{
	if (count == 0)
		return nullptr;
	BinSearchTree* max = this;
	while (max->right != nullptr)
	{
		max = max->right;
	}
	return max;
}

BinSearchTree * BinSearchTree::Min()
{
	if (count == 0)
		return nullptr;
	BinSearchTree* min = this;
	while (min->left != nullptr)
	{
		min = min->left;
	}
	return min;
}

BinSearchTree * BinSearchTree::Find(int data)
{
	if (count == 0)
		return nullptr;
	BinSearchTree* temp = this;
	while (temp->value != data)
	{
		if (temp->value > data)
		{
			if (temp->left)
				temp = temp->left;
			else
				return nullptr;
		}
		else
		{
			if (temp->right)
				temp = temp->right;
			else
				return nullptr;
		}
	}
	return temp;
}

BinSearchTree * BinSearchTree::Delete(int data)
{
	if (count == 0)
		return nullptr;
	BinSearchTree* temp = this;
	BinSearchTree* parent = nullptr;
	while (temp->value != data)
	{
		if (temp->value > data)
		{
			if (temp->left)
			{
				parent = temp;
				temp = temp->left;
			}
			else
				return nullptr;
		}
		else
		{
			if (temp->right)
			{
				parent = temp;
				temp = temp->right;
			}
			else
				return nullptr;
		}
	}

	if (temp->right == nullptr && temp->left == nullptr)
	{//左右孩子都为空
		if (temp == this)
		{
			this->count = 0;
			this->value = 0;
			return this;
		}
		else if(parent && parent->left == temp)
		{
			parent->left = nullptr;
		}
		else if (parent && parent->right == temp)
		{
			parent->right = nullptr;
		}
		delete temp;
	}

	else if (temp->right != nullptr && temp->left != nullptr)
	{//左右孩子都不为空
		parent = temp;
		BinSearchTree* delnode = temp->right;
		if (delnode->left)
		{
			while (delnode->left)
			{
				parent = delnode;
				delnode = delnode->left;
			}
			temp->value = delnode->value;
			parent->left = delnode->right;
		}
		else
		{
			temp->value = delnode->value;
			parent->right = delnode->right;
		}
		delete delnode;
	}

	else
	{//左孩子或右孩子不为空
		if (parent != nullptr && temp->left)
		{//左孩不为空
			if (parent->left == temp)	
				parent->left = temp->left;
			else
				parent->right = temp->left;
		}
		else if (parent != nullptr && temp->right)
		{//左孩不为空
			if (parent->left == temp)
				parent->left = temp->right;
			else
				parent->right = temp->right;
		}
		delete temp;
	}
}

void BinSearchTree::PreOrder(const BinSearchTree* root)
{
	if (!root)
		return;
	cout << root->value << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void BinSearchTree::PreOrder()
{
	if (!this->count)
		return;
	cout << this->value << " ";
	PreOrder(this->left);
	PreOrder(this->right);
}

void BinSearchTree::MidOrder(const BinSearchTree * root)
{
	if (root == nullptr)
		return;
	MidOrder(root->left);
	cout << root->value << " ";
	MidOrder(root->right);
}

void BinSearchTree::MidOrder()
{
	if (this->count == 0)
		return;
	MidOrder(this->left);
	cout << this->value << " ";
	MidOrder(this->right);
}

void BinSearchTree::MidOrder_Nonrecursive()
{
	if (count == 0)
		return;
	stack<BinSearchTree*> s;
	BinSearchTree* temp = this;
	while (!s.empty() || temp != nullptr)
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
			cout << temp->value << " ";
			temp = temp->right;
		}
	}
}

void BinSearchTree::FloorVist()
{
	if (!this->count)
		return;
	deque<BinSearchTree*> dequ;
	dequ.push_back(this);
	BinSearchTree* current = nullptr;
	while (dequ.size())
	{
		current = dequ.front();
		dequ.pop_front();
		cout << current->value << " ";
		if (current->left != nullptr)
			dequ.push_back(current->left);
		if (current->right != nullptr)
			dequ.push_back(current->right);
	}
}

int BinSearchTree::NumOfTree()
{
	cout << count << endl;
	if (count == 0)
		return 0;
	return(NumOfTree(this->right) + NumOfTree(this->left)) + 1;
}

int BinSearchTree::NumOfTree(BinSearchTree * node)
{
	if (node == nullptr)
		return 0;
	return(NumOfTree(node->right) + NumOfTree(node->left)) + 1;
}

int BinSearchTree::DepthOfTree()
{
	if (count == 0)
		return 0;
	int left = DepthOfTree(this->left);
	int right = DepthOfTree(this->right);
	return (left > right ? left : right) + 1;
}

int BinSearchTree::DepthOfTree(BinSearchTree * node)
{
	if (node == nullptr)
		return 0;
	int left = DepthOfTree(node->left);
	int right = DepthOfTree(node->right);
	return (left > right ? left : right) + 1;
}

int BinSearchTree::Width(int & width)
{
	if (count == 0)
		return 0;
	deque<BinSearchTree*> dequ;
	dequ.push_back(this);
	BinSearchTree* current;
	width = 0;
	int tempWidth = dequ.size();
	while (tempWidth)
	{
		if (tempWidth > width)
			width = tempWidth;
		while (tempWidth)
		{
			current = dequ.front();
			dequ.pop_front();
			if (current->left != nullptr)
				dequ.push_back(current->left);
			if (current->right != nullptr)
				dequ.push_back(current->right);
			tempWidth--;
		}
		tempWidth = dequ.size();
	}
}

void BinSearchTree::Routh(vector<BinSearchTree*>& vec, BinSearchTree * root)
{
	if (count == 0 || root == nullptr)
		return;
	vec.push_back(root);
	if (root->left == nullptr && root->right == nullptr)
	{
		vector<BinSearchTree*>::iterator itr = vec.begin();
		for (; itr != vec.end(); itr++)
		{
			cout << (*itr)->value << endl;
		}
		cout << "-----" << endl;
	}
	Routh(vec, root->left);
	Routh(vec, root->right);
	vec.pop_back();
}

bool BinSearchTree::JudeSame(BinSearchTree * first, BinSearchTree * second)
{
	if ((first == NULL && second == NULL) || (first->count == 0 && second->count == 0))
		return true;
	else if (!(first == nullptr) != !(second == nullptr))
		return false;
	if (first->value != second->value)
		return false;
	return (JudeSame(first->left, second->left) && JudeSame(first->right, second->right));
}

void BinSearchTree::Reverse(BinSearchTree * root)
{
	if (root == nullptr || root->count == 0)
		return;
	BinSearchTree* temp = nullptr;
	temp = root->right;
	root->right = root->left;
	root->left = temp;
	Reverse(root->left);
	Reverse(root->right);
}

void BinSearchTree::InsertFromOrderedArray(const int * array, int start, int end)
{
	if (start > end)
		return;
	this->left = nullptr;
	this->right = nullptr;
	//找到数组的中间作为根节点
	int mid = start + (end - start) / 2;
	this->value = array[mid];
	this->count++;
	InsertFromOrderedArray(this->left, array, start, mid - 1);
	InsertFromOrderedArray(this->right, array, mid + 1, end);
}

void BinSearchTree::InsertFromOrderedArray(BinSearchTree*& root, const int* array, int start, int end)
{
	if (start > end)
		return;
	root = new BinSearchTree;
	root->left = nullptr;
	root->right = nullptr;
	//找到数组的中间作为根节点
	int mid = start + (end - start) / 2;
	root->value = array[mid];
	this->count++;
	InsertFromOrderedArray(root->left, array, start, mid - 1);
	InsertFromOrderedArray(root->right, array, mid + 1, end);
}

BinSearchTree::~BinSearchTree()
{
}
