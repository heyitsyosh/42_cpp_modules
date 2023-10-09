#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>

class Weapon;

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack() const;
private:
	std::string _name;
	Weapon &_weapon;
};

#endif