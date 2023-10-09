#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream> //cout, endl

Character::Character()
: ICharacter(), name(""){
	// std::cout << "Character default constructor called" << std::endl;
	for(int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
}

Character::Character(const std::string &name)
: ICharacter() {
	// std::cout << "Character parameterized constructor called" << std::endl;
	this->name = name;
	for(int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
}

Character::Character(const Character &other)
: ICharacter(other), name(other.name) {
	// std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

Character &Character::operator=(const Character &other) {
	// std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < MAX_MATERIAS; i++) {
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
			else
				materias[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	// std::cout << "Character default destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		delete materias[i];
}

std::string const &Character::getName() const {
	return name;
}

void Character::equip(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (!materias[i]) {
			materias[i] = m;
			std::cout << "Equipped " << m->getType() << " materia!" << std::endl;
			return;
		}
	}
	std::cout << "Cannot equip " << m->getType() << " materia, no more slots available!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || MAX_MATERIAS <= idx) {
		std::cout << "Cannot unequip, index out of range!" << std::endl;
		return;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || MAX_MATERIAS <= idx) {
		std::cout << "Cannot use, index out of range!" << std::endl;
		return;
	}
	if (materias[idx]) {
		materias[idx]->use(target);
	}
	else {
		std::cout << "Cannot use, no materia equipped in slot!" << std::endl;
		return;
	}
}
