#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

// STL headers
#include <string>

// Forward declarations
class AMateria;

// Constants
#define MAX_MATERIAS 4

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();
	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
private:
	AMateria *materias[MAX_MATERIAS];
};

#endif