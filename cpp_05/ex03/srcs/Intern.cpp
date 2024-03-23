#include <iostream>
#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
	const std::string form_list[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;
	for (i = 0; i < 3; i++) {
		if (name == form_list[i])
			break;
	}
	if (0 <= i && i < 3)
		std::cout << "Intern creates " << form_list[i] << " form" << std::endl;
	switch (i) {
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			throw Intern::FormNotFoundException();
	}
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}
