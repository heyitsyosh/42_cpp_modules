#include <iostream> //cout, cerr, endl
#include <new> //bad_alloc
// #include <cstdlib> //system
#include <AAnimal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

#define GREEN "\033[32m"
#define RESET "\033[0m"

void test1() {
	std::cout << GREEN "[Test]" RESET << std::endl;
	const Cat cat;
	std::endl(std::cout);

	cat.makeSound();
	cat.AAnimal::makeSound();
	std::endl(std::cout);
}

void test2() {
	std::cout << GREEN  "[Test Pointer Ver.]" RESET << std::endl;
	const AAnimal *cat = new Cat();
	std::endl(std::cout);

	cat->makeSound();
	cat->AAnimal::makeSound();
	std::endl(std::cout);

	delete cat;
}

void test3() {
	std::cout << GREEN  "[Test Reference Ver.]" RESET << std::endl;
	const Cat cat;
	const AAnimal &ref = cat;
	std::endl(std::cout);

	ref.makeSound();
	ref.AAnimal::makeSound();
	std::endl(std::cout);
}

int main() {
	test1();
	std::endl(std::cout);
	test2();
	std::endl(std::cout);
	test3();
	// system("leaks ex02");

	return 0;
}
