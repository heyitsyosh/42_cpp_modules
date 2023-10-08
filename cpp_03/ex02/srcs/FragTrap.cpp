#include "FragTrap.hpp"
#include <iostream> //cout, endl

FragTrap::FragTrap() 
:	ClapTrap() {
	_hp = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) 
:	ClapTrap(name) {
	_hp = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
:	ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default destructor called" << std::endl;
}

void FragTrap::highFivesGuys() const {
	if (_hp)
		std::cout << "FragTrap " << _name << " says \"Hi five Guys!!\"" << std::endl;
	else
		std::cout << "FragTrap " << _name << " can't high five, it's dead!" << std::endl;
}
