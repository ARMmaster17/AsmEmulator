#pragma once
#include <sstream>
#include <vector>
#include <string>
static class StringHelpers
{
public:
	static std::vector<std::string> split(const std::string &text, char sep);
	static int stringToNumber(std::string s);
};
