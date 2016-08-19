#pragma once
#include "SFLAG_Register.h"
#include "RAM.h"
#include "GEN_Register.h"
#include <string>
#include <vector>

class Opcodes
{
public:
	static void run(SFLAG_Register &sfr, GEN_Register &gr, RAM &mem, std::vector<std::string> &cmd);
	static uint8_t getHexOpcode(std::string opcode);
	static void AAA(SFLAG_Register &sfr, GEN_Register &gr, RAM &mem, std::vector<std::string> &cmd);
	static void AAD(SFLAG_Register &sfr, GEN_Register &gr, RAM &mem);
};

