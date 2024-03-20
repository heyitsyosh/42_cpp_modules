#ifndef INTERN_HPP
#define INTERN_HPP

// STL headers
#include <string>

// Forward declarations
class AForm;

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	AForm *makeForm(const std::string &name, const std::string &target) const;
	class FormNotFoundException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif