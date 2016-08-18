#include "stdafx.h"
#include "SFLAG_Register.h"




SFLAG_Register::SFLAG_Register()
{
	
}


SFLAG_Register::~SFLAG_Register()
{

}

void SFLAG_Register::setFlag(std::string flagName, bool value)
{
	if (flagName == "TP") setFlag(8, value);
	else if (flagName == "IF") setFlag(9, value);
	else if (flagName == "NT") setFlag(14, value);
	else if (flagName == "RF") setFlag(16, value);
	else if (flagName == "VM") setFlag(17, value);
	else
	{
		// TODO: throw a triple-step error.
	}
}

void SFLAG_Register::setFlag(uint16_t bitLocation, bool value)
{
	registerStore[bitLocation] = value;
}

bool SFLAG_Register::getFlag(std::string flagName)
{
	if (flagName == "TP") return getFlag(8);
	else if (flagName == "IF") return getFlag(9);
	else if (flagName == "NT") return getFlag(14);
	else if (flagName == "RF") return getFlag(16);
	else if (flagName == "VM") return getFlag(17);
	else
	{
		// TODO: throw a triple-step error.
		// Just return 0 for now.
		return 0;
	}
}

bool SFLAG_Register::getFlag(uint16_t bitLocation)
{
	return registerStore[bitLocation];
}
