#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "Mage.h"
#include "Paladin.h"
#include "Ranger.h"
#include "Warrior.h"

class Guild
{
private:
	std::vector<std::shared_ptr<Adventurer>> chars;
	std::string _name;

	int _gold = 0,
	 rangers = 0,
	 warriors = 0,
	 paladins = 0,
	 mages = 0;
public:
	Guild(std::string name);
	~Guild();

	std::string GetName() const { return _name; }
	void AddChar(std::shared_ptr<Adventurer> _chars);

	std::string GetInfo();

	std::string AttackWithMages();
	std::string AttackWithPaladins();
	std::string AttackWithRangers();
	std::string AttackWithWarriors();
	std::string AttackWithAllAdventurers();
};

