#include "stdafx.h"
#include "StringHelpers.h"

using namespace std;

void StringHelpers::split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}


vector<string> StringHelpers::split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}
