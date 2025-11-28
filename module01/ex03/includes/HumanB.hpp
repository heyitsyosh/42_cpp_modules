#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>

class Weapon;

class HumanB {
public:
	HumanB();
	HumanB(const std::string &name);
	HumanB(const std::string &name, Weapon *weapon);
	~HumanB();
	void attack() const;
	void setWeapon(Weapon &weapon);
private:
	std::string _name;
	Weapon *_weapon;
};

#endif
