#pragma once
#include <string>
class GEN_Register
{
public:
	GEN_Register();
	~GEN_Register();
	void setReg_8(std::string flagName, uint8_t value);
	void setReg_16(std::string flagName, uint16_t value);
	void setReg_32(std::string flagName, uint32_t value);
	uint8_t getReg_8(std::string flagName);
	uint16_t getReg_16(std::string flagName);
	uint32_t getReg_32(std::string flagName);
};