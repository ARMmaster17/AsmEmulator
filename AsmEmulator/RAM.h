#pragma once
#include <iostream>
class RAM
{
public:
	RAM();
	~RAM();
	uint8_t read8Bits(long address);
	uint16_t read16Bits(long address);
	uint32_t read32Bits(long address);
	uint64_t read64Bits(long address);
	void write8Bits(long address, uint8_t value);
};

