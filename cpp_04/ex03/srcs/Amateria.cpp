#include "AMateria.hpp"
#include <iostream> //cout, endl

AMateria::AMateria()
:	type("") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) {
    std::cout << "AMateria parameterized constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria &other) 
: type(other.type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria default destructor called" << std::endl;
}

const std::string &AMateria::getType() const {
    return type;
}

void use(ICharacter& target) {
    //wtf should i do here
}
