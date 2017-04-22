#pragma once
#include <string>
#include "Adventurer.h"

class Warrior :public Adventurer
{
public:
	Warrior(std::string name);
	~Warrior();

	std::string Attack() { return _name + " shouts 'DO YOU LIKE MY SWORD SWORD SWORD MY DIAMOND SWORD!"; }
};

