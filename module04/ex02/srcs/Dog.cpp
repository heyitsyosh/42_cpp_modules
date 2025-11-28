#include <iostream> //cout, cerr, endl
#include <new> //bad_alloc
#include <cstdlib> //exit
#include <Dog.hpp>
#include <Brain.hpp>

Dog::Dog(): AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	try {
		_brain = new Brain();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Dog::Dog(const Dog &other): AAnimal(other), _brain(NULL) {
	std::cout << "Dog copy constructor called" << std::endl;
	try {
		_brain = new Brain();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
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

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "arf!" << std::endl;
}

void Dog::showIdeas() const {
	for (int i = 0; i < NUM_OF_IDEAS; i++) {
		const std::string &idea = _brain->getIdea(i);
		if (!idea.empty())
			std::cout << "Dog has an idea..." << idea << "!!" 
			<< " (address:" << &idea << ")" << std::endl;
	}
}

void Dog::setIdea(int i, std::string idea) const {
	_brain->setIdea(i, idea);
}
