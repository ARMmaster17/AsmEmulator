#include "../include/stdafx.h"
#include "../include/SFLAG_Register.h"

// Default class constructor.
SFLAG_Register::SFLAG_Register()
{
	
}

// Default class destructor.
SFLAG_Register::~SFLAG_Register()
{

}

// Sets the value of a flag in the SFLAG register.
void SFLAG_Register::setFlag(std::string flagName, bool value)
{
	if (flagName == "CF") setFlag(0, value);
	else if (flagName == "PF") setFlag(2, value);
	else if (flagName == "AF") setFlag(4, value);
	else if (flagName == "ZF") setFlag(6, value);
	else if (flagName == "SF") setFlag(7, value);
	else if (flagName == "TP") setFlag(8, value);
	else if (flagName == "IF") setFlag(9, value);
	else if (flagName == "OF") setFlag(11, value);
	else if (flagName == "NT") setFlag(14, value);
	else if (flagName == "RF") setFlag(16, value);
	else if (flagName == "VM") setFlag(17, value);
	else
	{
		// TODO: throw a triple-step error.
	}
}

// Sets the value of a flag based on it's bit location in the SFLAG register.
void SFLAG_Register::setFlag(uint16_t bitLocation, bool value)
{
	registerStore[bitLocation] = value;
}

// Gets the value of a flag from he SFLAG register.
bool SFLAG_Register::getFlag(std::string flagName)
{
	if (flagName == "CF") return getFlag(0);
	else if (flagName == "PF") return getFlag(2);
	else if (flagName == "AF") return getFlag(4);
	else if (flagName == "ZF") return getFlag(6);
	else if (flagName == "SF") return getFlag(7);
	else if (flagName == "TP") return getFlag(8);
	else if (flagName == "IF") return getFlag(9);
	else if (flagName == "OF") return getFlag(11);
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

// Gets the value of a flag in the SFLAG register.
bool SFLAG_Register::getFlag(uint16_t bitLocation)
{
	return registerStore[bitLocation];
}
