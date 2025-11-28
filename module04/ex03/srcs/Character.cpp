#include <iostream> //cout, cerr, endl
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(): ICharacter(), _name(""){
	// std::cout << "Character default constructor called" << std::endl;
	for(int i = 0; i < MAX_MATERIAS; i++)
		_materias[i] = NULL;
}

Character::Character(const std::string &name): ICharacter() {
	// std::cout << "Character parameterized constructor called" << std::endl;
	_name = name;
	for(int i = 0; i < MAX_MATERIAS; i++)
		_materias[i] = NULL;
}

Character::Character(const Character &other)
: ICharacter(other), _name(other._name) {
	// std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (other._materias[i])
			_materias[i] = other._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

Character &Character::operator=(const Character &other) {
	// std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < MAX_MATERIAS; i++) {
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	// std::cout << "Character default destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		delete _materias[i];
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (!_materias[i]) {
			_materias[i] = m;
			std::cout << "Equipped " << m->getType() << " materia!" << std::endl;
			return;
		}
	}
	std::cerr << "Cannot equip " << m->getType() << " materia, no more slots available!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || MAX_MATERIAS <= idx) {
		std::cerr << "Cannot unequip, index out of range!" << std::endl;
		return;
	}
	if (_materias[idx]) {
		std::cout << "Unequipped " << _materias[idx]->getType() << " materia!" << std::endl;
		_materias[idx] = NULL;
		return;
	}
	std::cerr << "Cannot unequip, no materia equipped in slot!" << std::endl;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || MAX_MATERIAS <= idx) {
		std::cerr << "Cannot use, index out of range!" << std::endl;
		return;
	}
	if (_materias[idx])
		_materias[idx]->use(target);
	else
		std::cerr << "Cannot use, no materia equipped in slot!" << std::endl;
}
