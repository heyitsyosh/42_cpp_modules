#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Brain;

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();
	void makeSound() const;
	void showIdeas() const;
	void setIdea(int i, std::string idea);
private:
	Brain *_brain;
};

#endif
