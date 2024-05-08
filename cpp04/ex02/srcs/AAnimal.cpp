#include <iostream> //cout, endl
#include <AAnimal.hpp>

AAnimal::AAnimal(): _type("") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other): _type(other._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other){
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal default destructor called" << std::endl;
}

void AAnimal::makeSound() const {
	std::cout << "* AAnimal noises *" << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}
