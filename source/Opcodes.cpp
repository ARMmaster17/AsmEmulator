#include "../include/stdafx.h"
#include "../include/Opcodes.h"

void Opcodes::run(SFLAG_Register &sfr, GEN_Register &gr, RAM &mem, std::vector<std::string> &cmd)
{
	// Get the numeric opcode
	uint8_t opcodeNumber = Opcodes::getHexOpcode(cmd[0]);
	if (opcodeNumber == 0x0)
	{
		return;
	}
	switch (opcodeNumber)
	{
	case 0x37:
		AAA(sfr, gr, mem, cmd);
	default:
		break;
	}
}

uint8_t Opcodes::getHexOpcode(std::string opcode)
{
	if (opcode == "AAA")
	{
		return 0x37;
	}
	else if (opcode == "MOV")
	{
		return 0xA4;
	}
	else
	{
		return 0x0;
	}
}

void Opcodes::AAA(SFLAG_Register &sfr, GEN_Register &gr, RAM &mem, std::vector<std::string> &cmd)
{
	if (((gr.getReg_8("AL") && 0x0F) > 9) || (sfr.getFlag("AF") == 1))
	{
		gr.setReg_8("AL", (gr.getReg_8("AL") + 6) && 0x0F);
	}
	else
	{
		sfr.setFlag("SF", 0);
		sfr.setFlag("AF", 0);
	}
}
