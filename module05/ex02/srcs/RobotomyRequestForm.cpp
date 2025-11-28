#include <cstdlib> //rand, srand, NULL
#include <ctime> //time
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", _grade_to_sign, _grade_to_exec), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", _grade_to_sign, _grade_to_exec), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeInDerived() const {
	std::cout << "Bzzzzz Bzzzzz Bzzzzz" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomization of " << _target << " has failed!" << std::endl;
}
