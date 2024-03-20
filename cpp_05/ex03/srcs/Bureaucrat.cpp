#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(lowest_grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: name(name), grade(grade)
{
	if (grade < highest_grade)
		throw Bureaucrat::GradeTooHighException();
	if (grade > lowest_grade)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade == highest_grade)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade == lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << name << " couldn't sign " << form.getName() 
		<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << name << " couldn't execute " << form.getName() 
		<< " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat) {
	return ostream << bureaucrat.getGrade() << ", bureaucrat grade " << bureaucrat.getName() << ".";
}
