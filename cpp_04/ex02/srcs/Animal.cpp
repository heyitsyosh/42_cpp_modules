#include <iostream> //cout, endl
#include <Animal.hpp>

Animal::Animal() 
: type("") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) 
: type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "* Animal noises *" << std::endl;
}

std::string Animal::getType() const {
	return type;
}
