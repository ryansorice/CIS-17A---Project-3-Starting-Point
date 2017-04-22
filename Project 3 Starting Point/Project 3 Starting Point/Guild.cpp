#include "Guild.h"
#include <memory>
#include <iterator>
#include <iostream>


Guild::Guild(std::string name)
{
	this->_name = name;
}

Guild::~Guild()
{
}

void Guild::AddChar(std::shared_ptr<Adventurer> _chars)
{
	chars.push_back(_chars);
}

std::string Guild::GetInfo()
{
	std::string output = "Your guild has: \n";
	int mages = 0, 
		rangers = 0, 
		warriors = 0,
		paladins = 0;

	for (std::vector<std::shared_ptr<Adventurer>>::iterator it = chars.begin(); it != chars.end(); it++)
	{
		if (std::dynamic_pointer_cast<Mage>(*it) != nullptr)
		{
			mages++;
		}
		else if (std::dynamic_pointer_cast<Ranger>(*it) != nullptr)
		{
			rangers++;
		}
		else if (std::dynamic_pointer_cast<Warrior>(*it) != nullptr)
		{
			warriors++;
		}
		else if (std::dynamic_pointer_cast<Paladin>(*it) != nullptr)
		{
			paladins++;
		}
	}

	output += mages		> 0 ? std::to_string(mages) + " mages\n" : "No mages!\n";
	output += rangers	> 0 ? std::to_string(rangers) + " rangers\n" : "No rangers!\n";
	output += warriors	> 0 ? std::to_string(warriors) + " warriors\n" : "No warriors!\n";
	output += paladins	> 0 ? std::to_string(paladins) + " paladins\n" : "No paladins!\n";

	return output;
}

std::string Guild::AttackWithMages()
{
	std::string output;
	for (std::vector<std::shared_ptr<Adventurer>>::iterator it = chars.begin(); it != chars.end(); it++)
	{
		if (std::dynamic_pointer_cast<Mage>(*it))
		{
			output += (*it)->attack();
		}
	}

	return output;
}

std::string Guild::AttackWithPaladins()
{
	std::string output;
	for (std::vector<std::shared_ptr<Adventurer>>::iterator it = chars.begin(); it != chars.end(); it++)
	{
		if (std::dynamic_pointer_cast<Paladin>(*it))
		{
			output += (*it)->attack();
		}
	}

	return output;
}

std::string Guild::AttackWithRangers()
{
	std::string output;
	for (std::vector<std::shared_ptr<Adventurer>>::iterator it = chars.begin(); it != chars.end(); it++)
	{
		if (std::dynamic_pointer_cast<Ranger>(*it))
		{
			output += (*it)->attack();
		}
	}

	return output;
}

std::string Guild::AttackWithWarriors()
{
	std::string output;
	for (std::vector<std::shared_ptr<Adventurer>>::iterator it = chars.begin(); it != chars.end(); it++)
	{
		if (std::dynamic_pointer_cast<Warrior>(*it))
		{
			output += (*it)->attack();
		}
	}

	return output;
}

std::string Guild::AttackWithAllAdventurers()
{
	std::string output = "You command everyone to attack! \n";
	output += AttackWithMages();
	output += AttackWithPaladins();
	output += AttackWithRangers();
	output += AttackWithWarriors();
	return output;
}
