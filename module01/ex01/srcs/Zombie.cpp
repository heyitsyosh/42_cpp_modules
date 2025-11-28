#include <iostream> //cout, end
#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) {
	_name = name;
}

Zombie::Zombie() {
	_name = "zombie";
}

Zombie::~Zombie() {
	std::cout << _name << ": *dies*" << std::endl;
}

void Zombie::setName(std::string name) {
	_name = name;
}

void Zombie::announce() const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
