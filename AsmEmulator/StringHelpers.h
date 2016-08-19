#pragma once
#include <sstream>
#include <vector>
#include <string>
static class StringHelpers
{
public:
	static void split(const std::string &s, char delim, std::vector<std::string> &elems);
	static std::vector<std::string> split(const std::string &s, char delim);
};

