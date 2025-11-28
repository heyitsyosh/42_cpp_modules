#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", _grade_to_sign, _grade_to_exec), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", _grade_to_sign, _grade_to_exec), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeInDerived() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}
