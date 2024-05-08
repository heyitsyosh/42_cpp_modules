#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	Zombie(const std::string &name);
	~Zombie();
	void announce() const;
private:
//	Variables
	std::string _name;
//	Functions
	Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
