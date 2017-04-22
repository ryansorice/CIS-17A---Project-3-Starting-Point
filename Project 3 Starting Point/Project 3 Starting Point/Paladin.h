#pragma once
#include <string>
#include "Adventurer.h"

class Paladin : public Adventurer
{
public:
	Paladin(std::string name);
	~Paladin();

	std::string Attack() { return _name + " swings a giant maul at his foes!"; }
};
