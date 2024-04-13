#include <iostream> //cout, endl
#include <climits>  // UINT_MAX
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name(""), _hp(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) 
: _name(name), _hp(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
:	_name(other._name),
	_hp(other._hp),
	_energy_points(other._energy_points),
	_attack_damage(other._attack_damage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()  {
	std::cout << "ClapTrap default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_energy_points && _hp > 0) {
		std::cout	<< "ClapTrap " << _name << " attacks " << target 
			<< ", causing " <<  _attack_damage << " points of damage!"
			<< std::endl;
		_energy_points--;
	}
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " can't attack, it has no more energy left!" << std::endl;
	else if (_hp == 0)
		std::cout << "ClapTrap " << _name << " can't attack, it's dead!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hp == 0)
		std::cout << "ClapTrap " << _name << " can't take damage, it's dead!" << std::endl;
	else {
		std::cout	<< "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
		if (amount > _hp)
			_hp = 0;
		else
			_hp -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_points && _hp > 0 && _hp < UINT_MAX) {
		std::cout	<< "ClapTrap " << _name << " repaired by " << amount << "!" << std::endl;
		if (_hp <= UINT_MAX - amount)
			_hp += amount;
		else
			_hp = UINT_MAX;
		_energy_points--;
	}
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired, it has no more energy left!" << std::endl;
	else if (_hp == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired, it's dead!" << std::endl;
	else if (_hp == UINT_MAX)
		std::cout	<< "ClapTrap " << _name << " can't be repaired, it already has full health!" << std::endl;
}
