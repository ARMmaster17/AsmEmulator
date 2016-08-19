#include "stdafx.h"
#include "StringHelpers.h"

using namespace std;

std::vector<std::string> StringHelpers::split(const std::string &text, char sep) {
	std::vector<std::string> tokens;
	std::size_t start = 0, end = 0;
	while ((end = text.find(sep, start)) != std::string::npos) {
		tokens.push_back(text.substr(start, end - start));
		start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}

int StringHelpers::stringToNumber(string s)
{
	istringstream convert(s);
	int result;
	if (!(convert >> result))
	{
		result = 0;
	}
	return result;
}