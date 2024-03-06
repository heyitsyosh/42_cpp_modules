#ifndef SHURBBERYCREATIONFORM_HPP
#define SHURBBERYCREATIONFORM_HPP

// Local headers
#include "AForm.hpp"

class ShrubberyRequestForm : public AForm {
public:
	ShrubberyRequestForm();
	ShrubberyRequestForm(const std::string &target);
	ShrubberyRequestForm(const ShrubberyRequestForm &other);
	ShrubberyRequestForm &operator=(const ShrubberyRequestForm &other);
	~ShrubberyRequestForm();
	void execute(const Bureaucrat &executor) const;
private:
	static const int grade_to_sign = 145;
	static const int grade_to_exec = 137;
	std::string target;
};

#endif
