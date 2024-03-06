#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
:	name("Default"),
	is_signed(false),
	grade_to_sign(lowest_grade),
	grade_to_execute(lowest_grade) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute)
:	name(name),
	is_signed(false),
	grade_to_sign(grade_to_sign),
	grade_to_execute(grade_to_execute) {
	if (grade_to_sign < highest_grade)
		throw Form::GradeTooHighException();
	if (grade_to_sign > lowest_grade)
		throw Form::GradeTooLowException();
	if (grade_to_execute < highest_grade)
		throw Form::GradeTooHighException();
	if (grade_to_execute > lowest_grade)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
:	name(other.name),
	is_signed(other.is_signed),
	grade_to_sign(other.grade_to_sign),
	grade_to_execute(other.grade_to_execute) {}

Form &Form::operator=(const Form &other) {
	if (this != &other) 
		is_signed = other.is_signed;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return is_signed;
}

int Form::getGradeToSign() const {
	return grade_to_sign;
}

int Form::getGradeToExecute() const {
	return grade_to_execute;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > grade_to_sign)
		throw Form::GradeTooLowException();
	is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw () {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw () {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &ostream, const Form &form) {
	ostream << "Form " << form.getName() 
	<< (form.getIsSigned() ? " is signed" : " is not signed") << std::endl
	<< "Required grade to sign is " << form.getGradeToSign() << std::endl
	<< "Required grade to sign is " << form.getGradeToExecute();
	return ostream;
}
