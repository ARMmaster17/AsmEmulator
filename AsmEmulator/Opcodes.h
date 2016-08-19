#pragma once
#include "SFLAG_Register.h"
#include "RAM.h"
#include "GEN_Register.h"
static class Opcodes
{
public:
	void AAA(SFLAG_Register* sfr, GEN_Register* gr, RAM* mem);
	void AAD(SFLAG_Register* sfr, GEN_Register* gr, RAM* mem);
};

