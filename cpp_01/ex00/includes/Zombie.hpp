#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
	Zombie(const std::string &name);
	~Zombie();
	void announce() const;
private:
	Zombie();
	std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
