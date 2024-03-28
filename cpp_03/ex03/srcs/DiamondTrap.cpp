#include <iostream> //cout, endl
#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap()
: ClapTrap(), ScavTrap(), FragTrap(), _name("") {
	_hp = FragTrap::default_hp;
	_energy_points = ScavTrap::default_energy_points;
	_attack_damage = FragTrap::default_attack_damage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
	_hp = FragTrap::default_hp;
	_energy_points = ScavTrap::default_energy_points;
	_attack_damage = FragTrap::default_attack_damage;
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name){
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name; 
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

void DiamondTrap::whoAmI() const {
	if (_hp) {
		std::cout	<< "Hey! My DiamondTrap name is " << _name
					<< ". My ClapTrap name is " << ClapTrap::_name << "!" <<std::endl;
	}
	else
		std::cout	<< "DiamondTrap " << _name << "doesn't have self-awareness, it's dead!" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::printAttributes() const {
	std::cout	<< "HP:" << _hp 
				<< " Energy Points: " << _energy_points 
				<< " Attack Damage: "  <<  _attack_damage << std::endl;
}
