#include "Zombie.hpp"
#include <iostream> //cout, endl

Zombie::Zombie(std::string name)
: _name(name) {}

Zombie::Zombie()
: _name("") {}

Zombie::~Zombie() {
	std::cout << _name << ": *dies*" << std::endl;
}

void Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
