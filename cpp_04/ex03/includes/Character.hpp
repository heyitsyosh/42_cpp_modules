#ifndef CHARACTER_HPP
#define CHARACTER_HPP

// STL headers
#include <string>

// Forward declarations
class AMateria;

// Constants
#define MAX_MATERIAS 4

class ICharacter {
public:
	virtual ~ICharacter() {}
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

class Character : public ICharacter{
public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
private:
	std::string name;
	AMateria *materias[MAX_MATERIAS];
};

#endif