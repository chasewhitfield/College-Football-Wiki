#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Name
{
	Name* left;
	Name* right;
	string name;
	vector<short> years; //active years
	unordered_map<short, pair<short, string>> season; //number and school in desired year

	Name(string name);
	Name* updateName(short number, string school, short year);
	void printInfo(); //prints number, school, year information
	void printNumber(short year); //prints number of player in a year
	void printSchool(short year); //prints school of player in a year
};