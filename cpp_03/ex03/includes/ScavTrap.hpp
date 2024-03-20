#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const std::string &name;
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
	void attack(const std::string &target);
	void guardGate();
protected:
	bool _guarding_gate;
	static const int default_hp = 100;
	static const int default_energy_points = 50;
	static const int default_attack_damage = 20;
};

#endif
