#include <iostream> //cout, cerr, endl
#include "Brain.hpp"

const std::string Brain::EMPTY_IDEA = "";

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < NUM_OF_IDEAS; i++)
		_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
		for (int i = 0; i < NUM_OF_IDEAS; i++)
			_ideas[i] = other._ideas[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain default destructor called" << std::endl;
}

const std::string &Brain::getIdea(int i) const {
	if (i >= 0 && i < NUM_OF_IDEAS)
		return _ideas[i];
	std::cerr << "Invalid starting index provided!" << std::endl;
	return (EMPTY_IDEA);
}

void Brain::setIdea(int i, std::string idea) {
	if (i >= 0 && i < NUM_OF_IDEAS)
		_ideas[i] = idea;
}
