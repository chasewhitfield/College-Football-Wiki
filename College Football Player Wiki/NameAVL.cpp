#include "NameAVL.h"
using namespace std;


bool isBalanced(NameAVL* node, int& balance);
int getHeight(NameAVL* node);
int maximum_N(int left, int right);
NameAVL* rotate(NameAVL* node, int parentBalance);
NameAVL* rotateLeft(NameAVL* node);
NameAVL* rotateRight(NameAVL* node);
NameAVL* rotateLeftRight(NameAVL* node);
NameAVL* rotateRightLeft(NameAVL* node);


NameAVL::NameAVL(string name)
{
	this->name = name;
	left = nullptr;
	right = nullptr;
}

NameAVL* NameAVL::updateName(short number, string school, short year)
{
	years.push_back(year);
	season[year] = { number, school };

	return this;
}

void NameAVL::printInfo()
{
	for (unsigned int i = 0; i < years.size(); i++)
		cout << years[i] << ": " << season[years[i]].first << ", " << season[years[i]].second << endl;
}

void NameAVL::printNumber(short year)
{
	if (season.find(year) != season.end())
		cout << season[year].first << endl;
	else
		cout << "Season not found!" << endl;
}

void NameAVL::printSchool(short year)
{
	if (season.find(year) != season.end())
		cout << season[year].second << endl;
	else
		cout << "Season not found!" << endl;
}



NameAVL* addNameAVL(NameAVL* node, string name)
{
	if (node == nullptr)
		return new NameAVL(name);

	if (name < node->name)
		node->left = addNameAVL(node->left, name);
	else
		node->right = addNameAVL(node->right, name);

	int balance;
	if (isBalanced(node, balance))
		return node;
	else
		return rotate(node, balance);
}

NameAVL* findNameAVL(NameAVL* node, string name)
{
	if (node == nullptr)
		return nullptr;

	if (name == node->name)
		return node;
	else if (name < node->name)
		return findNameAVL(node->left, name);
	else
		return findNameAVL(node->right, name);
}




bool isBalanced(NameAVL* node, int& balance)
{
	if (node == nullptr)
		return true;

	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);
	balance = leftHeight - rightHeight;

	if (balance > 1 || balance < -1)
		return false;

	return true;
}
int getHeight(NameAVL* node)
{
	if (node == nullptr)
		return 0;

	return 1 + maximum_N(getHeight(node->left), getHeight(node->right));
}
int maximum_N(int left, int right)
{
	if (left > right)
		return left;

	return right;
}
NameAVL* rotate(NameAVL* node, int parentBalance)
{
	int childBalance = 0;
	if (parentBalance > 0)
		isBalanced(node->left, childBalance);
	else
		isBalanced(node->right, childBalance);

	//left left case, rotate right
	if (parentBalance > 1 && childBalance > -1)
		return rotateRight(node);

	//right Right case, rotate left
	else if (parentBalance < -1 && childBalance < 1)
		return rotateLeft(node);

	//left right case, rotate left right
	else if (parentBalance > 1 && childBalance < 0)
		return rotateLeftRight(node);

	//right left case, rotate right left
	else if (parentBalance < -1 && childBalance > 0)
		return rotateRightLeft(node);

	else
		return node;
}
NameAVL* rotateLeft(NameAVL* node)
{
	NameAVL* grandchild = node->right->left;
	NameAVL* parent = node->right;
	parent->left = node;
	node->right = grandchild;

	return parent;
}
NameAVL* rotateRight(NameAVL* node)
{
	NameAVL* grandchild = node->left->right;
	NameAVL* parent = node->left;
	parent->right = node;
	node->left = grandchild;

	return parent;
}
NameAVL* rotateLeftRight(NameAVL* node)
{
	NameAVL* left = node->left;

	NameAVL* grandchild = left->right->left;
	NameAVL* parent = left->right;
	parent->left = left;
	left->right = grandchild;

	node->left = parent;

	grandchild = node->left->right;
	parent = node->left;
	parent->right = node;
	node->left = grandchild;

	return parent;
}
NameAVL* rotateRightLeft(NameAVL* node)
{
	NameAVL* right = node->right;

	NameAVL* grandchild = right->left->right;
	NameAVL* parent = right->left;
	parent->right = right;
	right->left = grandchild;

	node->right = parent;

	grandchild = node->right->left;
	parent = node->right;
	parent->left = node;
	node->right = grandchild;

	return parent;
}