// AsmEmulator.cpp : Defines the entry point for the console application.
//

#include "../include/stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "../include/StringHelpers.h"
#include "../include/Opcodes.h"

// Entry point for program.
int main()
{
	// Show startup statements.
	std::cout << "AsmEmulator v0.1" << std::endl;
	// Load in a new RAMDISK.
	std::cout << "Initializing RAMDISK." << std::endl;
	RAM *ram = new RAM();
	//////////////////////////////////////////////////////
	// Temporary testing code - remove in final release //
	// Holder for command input.
	std::string cmdHolder;
	// Console input loop.
	while (true)
	{
		// Reset to an empty value.
		cmdHolder = "";
		// Get input.
		std::cout << "> ";
		while (true)
		{
			std::getline(std::cin, cmdHolder);
			// If we get an enter key bounce, loop back.
			if (cmdHolder == "")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		// Split up the command into arguments.
		std::vector<std::string> splitCommand = StringHelpers::split(cmdHolder, ' ');
		// Check for exit condition.
		if (splitCommand[0] == "exit")
		{
			break;
		}
		// Dump the first 1000 bytes of memory.
		else if (splitCommand[0] == "dumpmem")
		{
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					printf("%X ", ram->read8Bits((i * 20) + j));
				}
				std::cout << std::endl;
			}
		}
			// Write an 8-bit value to memory.
		else if (splitCommand[0] == "writemem-8i")
		{
			ram->write8Bits(StringHelpers::stringToNumber(splitCommand[1]), StringHelpers::stringToNumber(splitCommand[2]));
			printf("Wrote value 0x%X to memory location 0x%X.\n", StringHelpers::stringToNumber(splitCommand[2]), StringHelpers::stringToNumber(splitCommand[1]));
		}
			// Treat command as an opcode.
		else
		{
			//Opcodes::run(nullptr, nullptr, *ram, splitCommand);
		}
	}
	//////////////////////////////////////////////////////
	return 0;
}

