#pragma once
#include <sstream>
#include <vector>
#include <string>
static class StringHelpers
{
public:
	std::vector<std::string> split(const std::string &text, char sep);
	int stringToNumber(std::string s);
};

