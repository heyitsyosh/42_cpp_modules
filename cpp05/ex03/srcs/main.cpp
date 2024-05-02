#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

void testForm(const std::string &form_name, const std::string &target) {
	Intern intern;
	try {
		AForm *form = intern.makeForm(form_name, target);
		delete form;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	std::cout << GREEN "[Test]" RESET << std::endl;
	testForm("shrubbery creation", "home");
	testForm("robotomy request", "home");
	testForm("presidential pardon", "home");
	testForm("invalid", "home");

	return 0;
}
