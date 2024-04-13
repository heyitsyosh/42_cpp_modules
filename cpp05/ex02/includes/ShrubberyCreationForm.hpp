#ifndef SHURBBERYCREATIONFORM_HPP
#define SHURBBERYCREATIONFORM_HPP

// Local headers
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	void executeInDerived() const;
private:
	static const int grade_to_sign = 145;
	static const int grade_to_exec = 137;
	std::string target;
};

#endif
