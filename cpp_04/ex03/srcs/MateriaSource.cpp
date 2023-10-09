#include "MateriaSource.hpp"
#include <iostream> //cout, endl

MateriaSource::MateriaSource()
:	IMateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for(int i = 0; i < MAX_MATERIAS; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
:	IMateriaSource(other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++) {
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
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
	std::cout << "MateriaSource default destructor called" << std::endl;
	//delete materias
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return;
}

AMateria *MateriaSource::createMateria(std::string const &type) {

}
