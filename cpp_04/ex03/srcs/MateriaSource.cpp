#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream> //cout, endl

MateriaSource::MateriaSource()
: IMateriaSource() {
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for(int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
: IMateriaSource(other) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	// std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < MAX_MATERIAS; i++) {
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
			else
				materias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	// std::cout << "MateriaSource default destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		delete materias[i];
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (!materias[i]) {
			materias[i] = m;
			std::cout << "Learned " << m->getType() << " materia!" << std::endl;
			return;
		}
	}
	std::cout << "Cannot learn " << m->getType() << " materia, no more slots available!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (materias[i] && materias[i]->getType() == type) {
			std::cout << "Created " << type << " materia!" << std::endl;
			return materias[i]->clone();
		}
	}
	std::cout << "Cannot create " << type << " materia, not found!" << std::endl;
	return NULL;
}
