#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct NameAVL
{
	NameAVL* left;
	NameAVL* right;
	string name;
	vector<short> years; //active years
	unordered_map<short, pair<short, string>> season; //number and school in desired year

	NameAVL(string name);
	NameAVL* updateName(short number, string school, short year);
	void printInfo(); //prints number, school, year information
	void printNumber(short year); //prints number of player in a year
	void printSchool(short year); //prints school of player in a year
};
