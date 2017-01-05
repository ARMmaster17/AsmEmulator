#include "../include/stdafx.h"
#include "../include/GEN_Register.h"
#include <bitset>

std::bitset<8> AL(0);
std::bitset<8> AH(0);
std::bitset<16> upperEAX(0);

std::bitset<8> DL(0);
std::bitset<8> DH(0);
std::bitset<16> upperEDX(0);

std::bitset<8> CL(0);
std::bitset<8> CH(0);
std::bitset<16> upperECX(0);

std::bitset<8> BL(0);
std::bitset<8> BH(0);
std::bitset<16> upperEBX(0);

std::bitset<16> BP(0);
std::bitset<16> upperEBP(0);

std::bitset<16> SI(0);
std::bitset<16> upperESI(0);

std::bitset<16> DI(0);
std::bitset<16> upperEDI(0);

std::bitset<16> SP(0);
std::bitset<16> upperESP(0);

GEN_Register::GEN_Register()
{
}

GEN_Register::~GEN_Register()
{
}
// Sets an 8-bit register.
void GEN_Register::setReg_8(std::string flagName, uint8_t value)
{
	if (flagName == "AL")
	{
		AL = std::bitset<8>(value);
	} else if (flagName == "AH")
	{
		AH = std::bitset<8>(value);
	}
    else if (flagName == "DL")
    {
        DL = std::bitset<8>(value);
    } else if (flagName == "DH")
    {
        DH = std::bitset<8>(value);
    }
    else if (flagName == "CL")
    {
        CL = std::bitset<8>(value);
    } else if (flagName == "CH")
    {
        CH = std::bitset<8>(value);
    }
    else if (flagName == "BL")
    {
        BL = std::bitset<8>(value);
    } else if (flagName == "BH")
    {
        BH = std::bitset<8>(value);
    }
}
// Sets a 16-bit register.
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
    else if (flagName == "upperEDX")
    {
        upperEDX = std::bitset<16>(value);
    }
    else if (flagName == "DX")
    {
        std::string DX = std::bitset<16>(value).to_string();
        DH = std::bitset<8>(DX.substr(0, 8));
        DL = std::bitset<8>(DX.substr(8, 8));
    }
    else if (flagName == "upperECX")
    {
        upperECX = std::bitset<16>(value);
    }
    else if (flagName == "CX")
    {
        std::string CX = std::bitset<16>(value).to_string();
        CH = std::bitset<8>(CX.substr(0, 8));
        CL = std::bitset<8>(CX.substr(8, 8));
    }
    else if (flagName == "upperEBX")
    {
        upperEBX = std::bitset<16>(value);
    }
    else if (flagName == "BX")
    {
        std::string BX = std::bitset<16>(value).to_string();
        BH = std::bitset<8>(BX.substr(0, 8));
        BL = std::bitset<8>(BX.substr(8, 8));
    }
    else if (flagName == "upperEBP")
    {
        upperEBP = std::bitset<16>(value);
    }
    else if (flagName == "BP")
    {
        BP = std::bitset<16>(value);
    }
    else if (flagName == "upperESI")
    {
        upperESI = std::bitset<16>(value);
    }
    else if (flagName == "SI")
    {
        SI = std::bitset<16>(value);
    }
    else if (flagName == "upperEDI")
    {
        upperEDI = std::bitset<16>(value);
    }
    else if (flagName == "DI")
    {
        DI = std::bitset<16>(value);
    }
    else if (flagName == "upperESP")
    {
        upperESP = std::bitset<16>(value);
    }
    else if (flagName == "SP")
    {
        SP = std::bitset<16>(value);
    }

}

// Sets a 32-bit register.
void GEN_Register::setReg_32(std::string flagName, uint32_t value)
{
	if (flagName == "EAX")
	{
		std::string EAX = std::bitset<32>(value).to_string();
		upperEAX = std::bitset<16>(EAX.substr(0, 16));
		AH = std::bitset<8>(EAX.substr(16, 8));
		AL = std::bitset<8>(EAX.substr(24, 8));
	}
    else if (flagName == "EDX")
    {
        std::string EDX = std::bitset<32>(value).to_string();
        upperEDX = std::bitset<16>(EDX.substr(0, 16));
        DH = std::bitset<8>(EDX.substr(16, 8));
        DL = std::bitset<8>(EDX.substr(24, 8));
    }
    else if (flagName == "ECX")
    {
        std::string ECX = std::bitset<32>(value).to_string();
        upperECX = std::bitset<16>(ECX.substr(0, 16));
        CH = std::bitset<8>(ECX.substr(16, 8));
        CL = std::bitset<8>(ECX.substr(24, 8));
    }
    else if (flagName == "EBX")
    {
        std::string EBX = std::bitset<32>(value).to_string();
        upperEBX = std::bitset<16>(EBX.substr(0, 16));
        BH = std::bitset<8>(EBX.substr(16, 8));
        BL = std::bitset<8>(EBX.substr(24, 8));
    }
    else if (flagName == "EBP")
    {
        std::string EBP = std::bitset<32>(value).to_string();
        upperEBP = std::bitset<16>(EBP.substr(0,16));
        BP = std::bitset<16>(EBP.substr(16, 16));
    }
    else if (flagName == "ESI")
    {
        std::string ESI = std::bitset<32>(value).to_string();
        upperESI = std::bitset<16>(ESI.substr(0,16));
        SI = std::bitset<16>(ESI.substr(16, 16));
    }
    else if (flagName == "EDI")
    {
        std::string EDI = std::bitset<32>(value).to_string();
        upperEDI = std::bitset<16>(EDI.substr(0,16));
        DI = std::bitset<16>(EDI.substr(16, 16));
    }
    else if (flagName == "ESP")
    {
        std::string ESP = std::bitset<32>(value).to_string();
        upperESP = std::bitset<16>(ESP.substr(0,16));
        SP = std::bitset<16>(ESP.substr(16, 16));
    }
}
// Gets the value of an 8-bit register.
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
    else if (flagName == "DH")
    {
        return (uint8_t)(DH.to_ulong());
    }
    else if (flagName == "DL")
    {
        return (uint8_t)(DL.to_ulong());
    }
    else if (flagName == "CH")
    {
        return (uint8_t)(CH.to_ulong());
    }
    else if (flagName == "CL")
    {
        return (uint8_t)(CL.to_ulong());
    }
    else if (flagName == "BH")
    {
        return (uint8_t)(BH.to_ulong());
    }
    else if (flagName == "BL")
    {
        return (uint8_t)(BL.to_ulong());
    }
}
// Gets the value of a 16-bit register.
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
    else if (flagName == "upperEDX")
    {
        return (uint16_t)(upperEDX.to_ulong());
    }
    else if (flagName == "DX")
    {
        return (uint16_t)(std::bitset<16>(DH.to_string() + DL.to_string()).to_ulong());
    }
    else if (flagName == "upperECX")
    {
        return (uint16_t)(upperECX.to_ulong());
    }
    else if (flagName == "CX")
    {
        return (uint16_t)(std::bitset<16>(CH.to_string() + CL.to_string()).to_ulong());
    }
    else if (flagName == "upperEBX")
    {
        return (uint16_t)(upperEBX.to_ulong());
    }
    else if (flagName == "BX")
    {
        return (uint16_t)(std::bitset<16>(BH.to_string() + BL.to_string()).to_ulong());
    }
    else if (flagName == "upperEBP")
    {
        return (uint16_t)(upperEBP.to_ulong());
    }
    else if (flagName == "BP")
    {
        return (uint16_t)(BP.to_ulong());
    }
    else if (flagName == "upperESI")
    {
        return (uint16_t)(upperESI.to_ulong());
    }
    else if (flagName == "SI")
    {
        return (uint16_t)(SI.to_ulong());
    }
    else if (flagName == "upperEDI")
    {
        return (uint16_t)(upperEDI.to_ulong());
    }
    else if (flagName == "DI")
    {
        return (uint16_t)(DI.to_ulong());
    }
    else if (flagName == "upperESP")
    {
        return (uint16_t)(upperESP.to_ulong());
    }
    else if (flagName == "SP")
    {
        return (uint16_t)(SP.to_ulong());
    }
}
// Gets the value of a 32-bit register.
uint32_t GEN_Register::getReg_32(std::string flagName)
{
	if (flagName == "EAX")
	{
		return (uint16_t)(std::bitset<32>(upperEAX.to_string() + AH.to_string() + AL.to_string()).to_ulong());
	}
    else if (flagName == "EDX")
    {
        return (uint16_t)(std::bitset<32>(upperEDX.to_string() + DH.to_string() + DL.to_string()).to_ulong());
    }
    else if (flagName == "ECX")
    {
        return (uint16_t)(std::bitset<32>(upperECX.to_string() + CH.to_string() + CL.to_string()).to_ulong());
    }
    else if (flagName == "EBX")
    {
        return (uint16_t)(std::bitset<32>(upperEBX.to_string() + BH.to_string() + BL.to_string()).to_ulong());
    }
    else if (flagName == "EBP")
    {
        return (uint16_t)(std::bitset<32>(upperEBP.to_string() + BP.to_string()).to_ulong());
    }
    else if (flagName == "ESI")
    {
        return (uint16_t)(std::bitset<32>(upperESI.to_string() + SI.to_string()).to_ulong());
    }
    else if (flagName == "EDI")
    {
        return (uint16_t)(std::bitset<32>(upperEDI.to_string() + DI.to_string()).to_ulong());
    }
    else if (flagName == "ESP")
    {
        return (uint16_t)(std::bitset<32>(upperESP.to_string() + SP.to_string()).to_ulong());
    }
}
