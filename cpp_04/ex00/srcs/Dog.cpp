#include "Dog.hpp"
#include <iostream> //cout, endl

Dog::Dog()
: Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &other) 
: Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "arf!" << std::endl;
}
