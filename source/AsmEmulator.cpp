// AsmEmulator.cpp : Defines the entry point for the console application.
//

#include "../include/stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "../include/StringHelpers.h"
#include "../include/Opcodes.h"

int main()
{
	std::cout << "AsmEmulator v0.1" << std::endl;
	std::cout << "Initializing RAMDISK." << std::endl;
	RAM *ram = new RAM();
	GEN_Register *gen = new GEN_Register();
	SFLAG_Register *sflag = new SFLAG_Register();
	//////////////////////////////////////////////////////
	// Temporary testing code - remove in final release //
	std::string cmdHolder;
	while (true)
	{
		cmdHolder = "";
		std::cout << "> ";
		while (true)
		{
			std::getline(std::cin, cmdHolder);
			if (cmdHolder == "")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		std::vector<std::string> splitCommand = StringHelpers::split(cmdHolder, ' ');
		if (splitCommand[0] == "exit")
		{
			break;
		}
		else if (splitCommand[0] == "dumpmem")
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					printf("%X ", ram->read8Bits((i * 20) + j));
				}
				std::cout << std::endl;
			}
		}
		else if (splitCommand[0] == "writemem-8i")
		{
			ram->write8Bits(StringHelpers::stringToNumber(splitCommand[1]), StringHelpers::stringToNumber(splitCommand[2]));
		}
		else
		{
			Opcodes::run(*sflag, *gen, *ram, splitCommand);
		}
	}
	//////////////////////////////////////////////////////
	return 0;
}
