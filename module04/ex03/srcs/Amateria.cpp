#include <iostream> //cout, endl
#include "AMateria.hpp"
#include "Character.hpp"

AMateria::AMateria(): _type("") {
	// std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) {
	// std::cout << "AMateria parameterized constructor called" << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria &other): _type(other._type) {
	// std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria() {
	// std::cout << "AMateria default destructor called" << std::endl;
}

const std::string &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	if (_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (_type == "cure")
		std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	else
		std::cerr << "Can't use, invalid type!" << std::endl;
}
