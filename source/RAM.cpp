#include "../include/stdafx.h"
#include "../include/RAM.h"

uint8_t memory[1000];

RAM::RAM()
{
	
}

RAM::~RAM()
{

}

uint8_t RAM::read8Bits(long address)
{
	return memory[address];
}

uint16_t RAM::read16Bits(long address)
{
	return (uint16_t)read8Bits(address) << 8 | read16Bits(address + 0x1);
}

uint32_t RAM::read32Bits(long address)
{
	return (uint32_t)read16Bits(address) << 16 | read16Bits(address + 0x1);
}

uint64_t RAM::read64Bits(long address)
{
	return (uint64_t)read32Bits(address) << 32 | read32Bits(address + 0x1);
}

void RAM::write8Bits(long address, uint8_t value)
{
	memory[address] = value;
}
