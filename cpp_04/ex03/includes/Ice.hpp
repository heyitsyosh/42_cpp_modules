#ifndef ICE_HPP
#define ICE_HPP

// Local headers
#include "AMateria.hpp"

// Forward declarations
class Character;

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice();
	AMateria *clone() const;
	void use(ICharacter &target) const;
};

#endif
