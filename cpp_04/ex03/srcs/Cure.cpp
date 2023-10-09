#include "Cure.hpp"
#include "Character.hpp"
#include <iostream> //cout, endl
#include <new> //new, bad_alloc
#include <cstdlib> //exit

Cure::Cure()
: AMateria("cure") {
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) 
: AMateria(other) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	// std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {
	// std::cout << "Cure default destructor called" << std::endl;
}

AMateria *Cure::clone() const {
	AMateria *clone;
	try {
		clone = new Cure();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	return clone;
}

void Cure::use(ICharacter &target) const {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
