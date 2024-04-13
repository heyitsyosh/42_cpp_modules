#include <iostream> //cout, endl
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *wrong = new WrongCat();
	std::endl(std::cout);

	std::cout << "Type is " << j->getType() << " " << std::endl;
	std::cout << "Type is " << i->getType() << " " << std::endl;
	std::cout << "Type is " << meta->getType() << " " << std::endl;
	std::cout << "Type is " << wrong->getType() << " \n" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();
	std::endl(std::cout);

	delete meta;
	delete j;
	delete i;
	delete wrong;

	return 0;
}
