#include "../include/stdafx.h"
#include "../include/GEN_Register.h"
#include <bitset>

std::bitset<8> AL(0);
std::bitset<8> AH(0);
std::bitset<16> upperEAX(0);

GEN_Register::GEN_Register()
{
}

GEN_Register::~GEN_Register()
{
}

void GEN_Register::setReg_8(std::string flagName, uint8_t value)
{
	if (flagName == "AL")
	{
		AL = std::bitset<8>(value);
	}
	else if (flagName == "AX")
	{
		AH = std::bitset<8>(value);
	}
}

void GEN_Register::setReg_16(std::string flagName, uint16_t value)
{
	if (flagName == "upperEAX")
	{
		upperEAX = std::bitset<16>(value);
	}
	else if (flagName == "AX")
	{
		std::string AX = std::bitset<16>(value).to_string();
		AH = std::bitset<8>(AX.substr(0, 8));
		AL = std::bitset<8>(AX.substr(8, 8));
	}
}

void GEN_Register::setReg_32(std::string flagName, uint32_t value)
{
	if (flagName == "EAX")
	{
		std::string EAX = std::bitset<32>(value).to_string();
		upperEAX = std::bitset<16>(EAX.substr(0, 16));
		AH = std::bitset<8>(EAX.substr(16, 8));
		AL = std::bitset<8>(EAX.substr(24, 8));
	}
}

uint8_t GEN_Register::getReg_8(std::string flagName)
{
	if (flagName == "AH")
	{
		return (uint8_t)(AH.to_ulong());
	}
	else if (flagName == "AL")
	{
		return (uint8_t)(AL.to_ulong());
	}
}

uint16_t GEN_Register::getReg_16(std::string flagName)
{
	if (flagName == "upperEAX")
	{
		return (uint16_t)(upperEAX.to_ulong());
	}
	else if (flagName == "AX")
	{
		return (uint16_t)(std::bitset<16>(AH.to_string() + AL.to_string()).to_ulong());
	}
}

uint32_t GEN_Register::getReg_32(std::string flagName)
{
	if (flagName == "EAX")
	{
		return (uint16_t)(std::bitset<32>(upperEAX.to_string() + AH.to_string() + AL.to_string()).to_ulong());
	}
}
