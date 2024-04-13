#include <iostream> //cout, endl
#include <new> //bad_alloc
#include <cstdlib> //exit
#include <Cat.hpp>
#include <Brain.hpp>

Cat::Cat() 
: AAnimal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	try {
		this->brain = new Brain();
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Cat::Cat(const Cat &other) 
:	AAnimal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	try {
		this->brain = new Brain(*other.brain);
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
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

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const {
	std::cout << "purrr!" << std::endl;
}

void Cat::showIdeas() const {
	for (int i = 0; i < NUM_OF_IDEAS; i++) {
		const std::string &idea = brain->getIdea(i);
		if (!idea.empty())
			std::cout << "Cat has an idea..." << idea << "!!" 
			<< " (address:" << &idea << ")" << std::endl;
	}
}

void Cat::setIdea(int i, std::string idea) const {
	brain->setIdea(i, idea);
}
