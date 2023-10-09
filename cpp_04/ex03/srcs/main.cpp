#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream> //cout, cerr, endl
// #include <cstdlib> //system

# define GREEN "\033[32m"
# define RESET "\033[0m"

void test1() {
	std::cout << GREEN  "[Test 1 (from subject.pdf)]" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void test2() {
	std::cout << GREEN  "[Test 2]" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	Cure *cures[MAX_MATERIAS + 1];
	AMateria* tmp;

	for (int i = 0; i < MAX_MATERIAS + 1; i++)
		cures[i] = new Cure();

	tmp = src->createMateria("fire");
	tmp = src->createMateria("cure");
	std::endl(std::cout);

	for (int i = 0; i < MAX_MATERIAS + 1; i++)
		src->learnMateria(cures[i]);
	std::endl(std::cout);

	me->use(0, *me);
	std::endl(std::cout);

	for (int i = 0; i < MAX_MATERIAS + 1; i++) {
		tmp = src->createMateria("cure");
		me->equip(tmp);
	}
	std::endl(std::cout);

	me->use(MAX_MATERIAS, *me);

	delete me;
	delete src;
	delete tmp;
	delete cures[MAX_MATERIAS];
}

int main() {
	test1();
	std::endl(std::cout);
	test2();
	// system("leaks ex03");

	return 0;
}
