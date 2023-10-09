#include "ScavTrap.hpp"
#include <iostream> //cout, endl

ScavTrap::ScavTrap() 
: ClapTrap(), _guarding_gate(false) {
	_hp = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
: ClapTrap(name), _guarding_gate(false) {
	_hp = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) 
: ClapTrap(other), _guarding_gate(other._guarding_gate) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		_guarding_gate = other._guarding_gate;
	}
	return *this;
}

ScavTrap::~ScavTrap()  {
	std::cout << "ScavTrap default destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (_energy_points && _hp > 0) {
		std::cout	<< "ScavTrap " << _name << " attacks " << target 
			<< ", causing " <<  _attack_damage << " points of damage!"
			<< std::endl;
		_energy_points--;
	}
	else if (_energy_points == 0)
		std::cout << "ScavTrap " << _name << " can't attack, it has no more energy left!" << std::endl;
	else if (_hp == 0)
		std::cout << "ScavTrap " << _name << " can't attack, it's dead!" << std::endl;
}

void ScavTrap::guardGate() {
	if (_guarding_gate)
		std::cout << "ScavTrap " << _name << " is already guarding gate!" << std::endl;
	else if (_energy_points == 0)
		std::cout << "ScavTrap " << _name << " can't guard the gate, it has no more energy left!" << std::endl;
	else {
		_guarding_gate = true;
		_energy_points--;
		std::cout << "ScavTrap " << _name << " is now guarding the gate!" << std::endl;
	}
}
