#include <iostream> //cout, cerr, endl
#include <sstream> //stringstream
// #include <cstdlib> //system
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

# define NUM_OF_ANIMALS 4

void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::endl(std::cout);

	delete j; //should not create a leak
	delete i;
}

void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	const Animal *animals[6];

	for (int i = 0; i < NUM_OF_ANIMALS / 2; i++)
		animals[i] = new Cat();
	for (int i = NUM_OF_ANIMALS / 2; i < NUM_OF_ANIMALS; i++)
		animals[i] = new Dog();
	std::endl(std::cout);

	for (int i = 0; i < NUM_OF_ANIMALS; i++)
		delete animals[i];
}

std::string iToStr(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

void test3() {
	std::cout << GREEN "[Test 3]" RESET << std::endl;
	Cat cat;
	std::endl(std::cout);

	for (int i = 0; i < 30; i++)
		cat.setIdea(i, "it's " + iToStr(i + 1));
	cat.showIdeas();
	std::endl(std::cout);

	Cat copy(cat);
	std::cout << GREEN << "cat address: " << &cat << ", copy address:" << &copy << RESET << std::endl;
	std::endl(std::cout);
	copy.showIdeas();
	std::endl(std::cout);
}


int main() {
	test1();
	std::endl(std::cout);
	test2();
	std::endl(std::cout);
	test3();
	// system("leaks ex01");

	return 0;
}
