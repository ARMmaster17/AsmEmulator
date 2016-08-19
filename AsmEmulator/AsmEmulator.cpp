// AsmEmulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "StringHelpers.h"
#include "Opcodes.h"

int main()
{
	std::cout << "AsmEmulator v0.1" << std::endl;
	//////////////////////////////////////////////////////
	// Temporary testing code - remove in final release //
	std::string cmdHolder;
	while (true)
	{
		cmdHolder = "";
		std::cout << "> ";
		while (true)
		{
			std::cin >> cmdHolder;
			if (cmdHolder == "")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		std::cout << std::endl;
		std::vector<std::string> splitCommand = StringHelpers::split(cmdHolder, ' ');
		Opcodes::run(nullptr, nullptr, nullptr, splitCommand);
	}
	//////////////////////////////////////////////////////
	return 0;
}

