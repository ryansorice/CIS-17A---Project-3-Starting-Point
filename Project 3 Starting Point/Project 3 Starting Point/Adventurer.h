#pragma once
#include <string>

class Adventurer
{
	
public:
	std::string _name;

	Adventurer(std::string name);
	Adventurer();
	~Adventurer();

	std::string getName() { return _name; }
	std::string attack() { return getName() + " attacks with bare hands!"; }
};

