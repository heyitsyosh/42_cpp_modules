#include "HumanB.hpp"
#include <iostream> //cout, endl

HumanB::HumanB() {}

HumanB::HumanB(std::string name)
: _name(name), _weapon(NULL)
{
}

HumanB::HumanB(std::string name, Weapon *weapon)
: _name(name), _weapon(weapon)
{
}

HumanB::~HumanB() {}

void HumanB::attack() const {
	std::cout << _name << " attacks with their ";
	if (_weapon)
		std::cout << _weapon->getType() << std::endl;
	else
		std::cout << "bare hands!" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
