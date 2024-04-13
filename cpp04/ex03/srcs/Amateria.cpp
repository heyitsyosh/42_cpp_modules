#include <iostream> //cout, endl
#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria()
: type("") {
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) {
	// std::cout << "AMateria parameterized constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &other) 
: type(other.type) {
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria() {
	// std::cout << "AMateria default destructor called" << std::endl;
}

const std::string &AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (type == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else
		std::cout << "Can't use, invalid type!" << std::endl;
}
