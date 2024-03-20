#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:	AForm("PresidentialPardonForm", grade_to_sign, grade_to_exec), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:	AForm("PresidentialPardonForm", grade_to_sign, grade_to_exec), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeInDerived() const {
	std::cout << target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
