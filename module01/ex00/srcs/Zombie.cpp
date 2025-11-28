#include <iostream> //cout, endl
#include "Zombie.hpp"

Zombie::Zombie(const std::string &name)
: _name(name) {}

Zombie::Zombie()
: _name("") {}

Zombie::~Zombie() {
	std::cout << _name << ": *dies*" << std::endl;
}

void Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
