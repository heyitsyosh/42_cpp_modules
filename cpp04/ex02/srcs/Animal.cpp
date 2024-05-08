#include <iostream> //cout, endl
#include <Animal.hpp>

Animal::Animal(): _type("") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other): _type(other._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "* Animal noises *" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
