#include <iostream> //cout, endl
#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other) 
: WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "pirrr!" << std::endl;
}
