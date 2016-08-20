#pragma once
#include <sstream>
#include <vector>
#include <string>
class StringHelpers
{
public:
	static std::vector<std::string> split(const std::string &text, char sep);
	static int stringToNumber(std::string s);
};

