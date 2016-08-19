#include "stdafx.h"
#include "Opcodes.h"

void Opcodes::AAA(SFLAG_Register * sfr, GEN_Register * gr, RAM * mem)
{
	if (((gr->getReg_8("AL")/* && 0FH*/) > 9) || (sfr->getFlag("AF") == 1))
	{
		gr->setReg_8("AL", (gr->getReg_8("AL") + 6)/* && 0FH*/);
	}
	else
	{
		sfr->setFlag("SF", 0);
		sfr->setFlag("AF", 0);
	}
}

void Opcodes::AAD(SFLAG_Register * sfr, GEN_Register * gr, RAM * mem)
{
}
