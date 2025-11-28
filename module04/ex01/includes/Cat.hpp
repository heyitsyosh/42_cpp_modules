#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Brain;

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	void makeSound() const;
	void showIdeas() const;
	void setIdea(int i, std::string idea);
private:
	Brain *_brain;
};

#endif
