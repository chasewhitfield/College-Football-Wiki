#include "Name.h"
using namespace std;


Name::Name(string name)
{
	this->name = name;
	left = nullptr;
	right = nullptr;
}

Name* Name::updateName(short number, string school, short year)
{
	years.push_back(year);
	season[year] = { number, school };

	return this;
}

void Name::printInfo()
{
	for (unsigned int i = 0; i < years.size(); i++)
		cout << years[i] << ": " << season[years[i]].first << ", " << season[years[i]].second << endl;
}

void Name::printNumber(short year)
{
	if (season.find(year) != season.end())
		cout << season[year].first << endl;
	else
		cout << "Season not found!" << endl;
}

void Name::printSchool(short year)
{
	if (season.find(year) != season.end())
		cout << season[year].second << endl;
	else
		cout << "Season not found!" << endl;
}


Name* addName(Name* node, string name)
{
	if (node == nullptr)
		return new Name(name);

	if (name < node->name)
		node->left = addName(node->left, name);
	else
		node->right = addName(node->right, name);

	return node;
}

Name* findName(Name* node, string name)
{
	if (node == nullptr)
		return nullptr;

	if (name == node->name)
		return node;
	else if (name < node->name)
		return findName(node->left, name);
	else
		return findName(node->right, name);
}