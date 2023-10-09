#include "Ice.hpp"
#include <iostream> //cout, endl
#include <new> //new, bad_alloc

Ice::Ice()
:	AMateria() {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &other) 
: AMateria(other) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice default destructor called" << std::endl;
}

AMateria *Ice::clone() const {
    AMateria *clone;
    try {
        clone = new Ice();
    }
    catch (const std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }
    return clone;
}

void Ice::use(ICharacter &target) const {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
