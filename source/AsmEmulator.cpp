// AsmEmulator.cpp : Defines the entry point for the console application.
//

#include "../include/stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "../include/StringHelpers.h"
#include "../include/Opcodes.h"

// Entry point for program.
int main() {
    // Show startup statements.
    std::cout << "AsmEmulator v0.1" << std::endl;
    // Load in a new RAMDISK.
    std::cout << "Initializing RAMDISK." << std::endl;
    RAM *ram = new RAM();
    GEN_Register *gen = new GEN_Register();
    SFLAG_Register *sflag = new SFLAG_Register();
    //////////////////////////////////////////////////////
    // Temporary testing code - remove in final release //
    // Holder for command input.
    std::string cmdHolder;
    // Console input loop.
    while (true) {
        // Reset to an empty value.
        cmdHolder = "";
        // Get input.
        std::cout << "> ";
        while (true) {
            std::getline(std::cin, cmdHolder);
            // If we get an enter key bounce, loop back.
            if (cmdHolder == "") {
                continue;
            } else {
                break;
            }
        }
        // Split up the command into arguments.
        std::vector<std::string> splitCommand = StringHelpers::split(cmdHolder, ' ');
        // Check for exit condition.
        if (splitCommand[0] == "exit") {
            break;
        }
            // Dump the first 1000 bytes of memory.
        else if (splitCommand[0] == "dumpmem") {
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 50; j++) {
                    printf("%X ", ram->read8Bits((i * 20) + j));
                }
                std::cout << std::endl;
            }
        }
            // Dump all values in the registry.
        else if (splitCommand[0] == "dumpgenregs") {
            printf("AL: %X\n", gen->getReg_8("AL"));
            printf("AH: %X\n", gen->getReg_8("AH"));
            printf("AX: %X\n", gen->getReg_16("AX"));
            printf("EAX: %X\n", gen->getReg_32("EAX"));

            printf("DL: %X\n", gen->getReg_8("DL"));
            printf("DH: %X\n", gen->getReg_8("DH"));
            printf("DX: %X\n", gen->getReg_16("DX"));
            printf("EDX: %X\n", gen->getReg_32("EDX"));

            printf("CL: %X\n", gen->getReg_8("CL"));
            printf("CH: %X\n", gen->getReg_8("CH"));
            printf("CX: %X\n", gen->getReg_16("CX"));
            printf("ECX: %X\n", gen->getReg_32("ECX"));

            printf("BL: %X\n", gen->getReg_8("BL"));
            printf("BH: %X\n", gen->getReg_8("BH"));
            printf("BX: %X\n", gen->getReg_16("BX"));
            printf("EBX: %X\n", gen->getReg_32("EBX"));

            printf("BP: %X\n", gen->getReg_16("BP"));
            printf("EBP: %X\n", gen->getReg_32("EBP"));

            printf("SI: %X\n", gen->getReg_16("SI"));
            printf("ESI: %X\n", gen->getReg_32("ESI"));

            printf("DI: %X\n", gen->getReg_16("DI"));
            printf("EDI: %X\n", gen->getReg_32("EDI"));

            printf("SP: %X\n", gen->getReg_16("SP"));
            printf("ESP: %X\n", gen->getReg_32("ESP"));
        } else if (splitCommand[0] == "setgenreg") {
            if (splitCommand[1] == "8") {
                gen->setReg_8(splitCommand[2], StringHelpers::stringToNumber(splitCommand[3]));
            }
        }
            // Write an 8-bit value to memory.
        else if (splitCommand[0] == "writemem-8i") {
            ram->write8Bits(StringHelpers::stringToNumber(splitCommand[1]),
                            StringHelpers::stringToNumber(splitCommand[2]));
            printf("Wrote value 0x%X to memory location 0x%X.\n", StringHelpers::stringToNumber(splitCommand[2]),
                   StringHelpers::stringToNumber(splitCommand[1]));
        }
            // Treat command as an opcode.
        else {
            Opcodes::run(*sflag, *gen, *ram, splitCommand);
        }
    }
    //////////////////////////////////////////////////////
    return 0;
}
