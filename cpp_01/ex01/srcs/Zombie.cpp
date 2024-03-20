#include "Zombie.hpp"
#include <iostream> //cout, endl

Zombie::Zombie(const std::string &name) {
	this->name = name;
}

Zombie::Zombie() {
	this->name = "zombie";
}

Zombie::~Zombie() {
	std::cout << name << ": *dies*" << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}

void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
