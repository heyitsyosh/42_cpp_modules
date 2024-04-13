#ifndef CURE_HPP
#define CURE_HPP

// Local headers
#include "AMateria.hpp"

// Forward declarations
class Character;

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();
	AMateria *clone() const;
	void use(ICharacter &target) const;
};

#endif
