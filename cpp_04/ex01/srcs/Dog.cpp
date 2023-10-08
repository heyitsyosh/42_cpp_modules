#include "Dog.hpp"
#include <iostream> //cout, endl
#include <new> //new, bad_alloc
#include <cstdlib> //exit

Dog::Dog()
:	Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	try {
		this->brain = new Brain();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Dog::Dog(const Dog &other) 
: Animal(other), brain(NULL) {
	std::cout << "Dog copy constructor called" << std::endl;
	try {
		this->brain = new Brain();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		try {
			this->brain = new Brain(*other.brain);
		}
		catch (const std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
			std::exit(1);
		}
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "arf!" << std::endl;
}

void Dog::showIdeas() const {
	for (int i = 0; i < NUM_OF_IDEAS; i++) {
		const std::string &idea = brain->getIdea(i);
		if (!idea.empty())
			std::cout << "Cat has an idea..." << idea << "!!" 
			<< " (address:" << &idea << ")" << std::endl;
	}
}

void Dog::setIdea(int i, std::string idea) {
	brain->setIdea(i, idea);
}
