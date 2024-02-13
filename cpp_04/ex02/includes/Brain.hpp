#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define NUM_OF_IDEAS 100

class Brain {
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
	const std::string &getIdea(int i) const;
	void setIdea(int i, std::string idea);
private:
	std::string ideas[NUM_OF_IDEAS];
	static const std::string EMPTY_IDEA;
};

#endif
