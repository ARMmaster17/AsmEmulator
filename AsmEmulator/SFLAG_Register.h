#pragma once
#include <string>
class SFLAG_Register
{
public:
	SFLAG_Register();
	~SFLAG_Register();
	void setFlag(std::string flagName, bool value);
	void setFlag(uint16_t bitLocation, bool value);
	bool getFlag(std::string flagName);
	bool getFlag(uint16_t bitLocation);
private:
	bool registerStore [32];
};

