#include "../include/stdafx.h"
#include "../include/RAM.h"

// byte array to hold entire RAMdisk.
uint8_t memory[1000];

// Default class initializer.
RAM::RAM()
{
	
}

// Default class destructor.
RAM::~RAM()
{

}

// Read an 8-bit value from memory.
uint8_t RAM::read8Bits(long address)
{
	return memory[address];
}

// Read a 16-bit value from memory.
uint16_t RAM::read16Bits(long address)
{
	return (uint16_t)read8Bits(address) << 8 | read16Bits(address + 0x1);
}

// Read a 32-bit value from memory.
uint32_t RAM::read32Bits(long address)
{
	return (uint32_t)read16Bits(address) << 16 | read16Bits(address + 0x1);
}

// Write an 8-bit value to memory.
void RAM::write8Bits(long address, uint8_t value)
{
	memory[address] = value;
}

// Write a 16-bit value to memory.
void RAM::write16Bits(long address, uint16_t value)
{

}

// Write a 32-bit value to memory.
void RAM::write32Bits(long address, uint32_t value)
{

}
