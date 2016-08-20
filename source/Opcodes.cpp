#include "../include/stdafx.h"
#include "../include/Opcodes.h"

// Takes in a command parameter and interprets it into an assembly opcode and executes it.
void Opcodes::run(SFLAG_Register &sfr, GEN_Register &gr, RAM &mem, std::vector<std::string> &cmd)
{
	// Get the numeric opcode.
	uint8_t opcodeNumber = Opcodes::getHexOpcode(cmd[0]);
	// Check to see if the opcode is valid.
	if (opcodeNumber == 0x0)
	{
		// This opcode is not valid. Return for now.
		// TODO: Throw a triple-step error.
		return;
	}
	// Opcode is valid, compare it against the list of added opcode functions.
	switch (opcodeNumber)
	{
	case 0x37:
		AAA(sfr, gr, mem, cmd);
	default:
		break;
	}
}

// Get the 8-bit hexadecimal opcode of the given ASM command.
uint8_t Opcodes::getHexOpcode(std::string opcode)
{
	if (opcode == "AAA")
	{
		return 0x37;
	}
	else if (opcode == "MOV")
	{
		// NOTE: MOV has multiple supported commands.
		// TODO: Find a way to expand out to correct opcode depending on argument types.
		return 0xA4;
	}
	else
	{
		// No opcode found. Return 0.
		return 0x0;
	}
}

// ASCII Adjust after Addition.
// Page 256 of the Intel 80386 Programmers Reference Manual.
void Opcodes::AAA(SFLAG_Register &sfr, GEN_Register &gr, RAM &mem, std::vector<std::string> &cmd)
{
	if (((gr.getReg_8("AL") & 0x0F) > 9) || (sfr.getFlag("AF") == 1))
	{
		gr.setReg_8("AL", (gr.getReg_8("AL") + 6) & 0x0F);
	}
	else
	{
		sfr.setFlag("SF", 0);
		sfr.setFlag("AF", 0);
	}
}
