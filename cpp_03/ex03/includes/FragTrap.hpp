#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();
	void highFivesGuys() const;
protected:
	static const int default_hp = 100;
	static const int default_energy_points = 100;
	static const int default_attack_damage = 30;
};

#endif