#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"

class Brain;

class Cat : public AAnimal {
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();
	void makeSound() const;
	void showIdeas() const;
	void setIdea(int i, std::string idea) const;
private:
	Brain *brain;
};

#endif