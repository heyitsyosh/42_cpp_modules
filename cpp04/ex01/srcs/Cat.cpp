#include <iostream> //cout, endl
#include <new> //bad_alloc
#include <cstdlib> //exit
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	try {
		_brain = new Brain();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Cat::Cat(const Cat &other): Animal(other), _brain(NULL) {
	std::cout << "Cat copy constructor called" << std::endl;
	try {
		_brain = new Brain(*other._brain);
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
		delete _brain;
		try {
			_brain = new Brain(*other._brain);
		}
		catch (const std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
			std::exit(1);
		}
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "purrr!" << std::endl;
}

void Cat::showIdeas() const {
	for (int i = 0; i < NUM_OF_IDEAS; i++) {
		const std::string &idea = _brain->getIdea(i);
		if (!idea.empty())
			std::cout << "Cat has an idea..." << idea << "!!"
			<< " (address:" << &idea << ")" << std::endl;
	}
}

void Cat::setIdea(int i, std::string idea) {
	_brain->setIdea(i, idea);
}
