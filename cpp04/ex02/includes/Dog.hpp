#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Brain;

class Dog : public AAnimal {
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();
	void makeSound() const;
	void showIdeas() const;
	void setIdea(int i, std::string idea) const;
private:
	Brain *_brain;
};

#endif
