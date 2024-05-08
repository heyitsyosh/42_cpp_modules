#ifndef AMATERIA_HPP
#define AMATERIA_HPP

// STL headers
#include <string>

// Forward declarations
class ICharacter;

class AMateria {
public:
	AMateria();
	AMateria(const std::string &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
protected:
	std::string _type;
};

#endif
