#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
:	_name("Default"),
	_is_signed(false),
	_grade_to_sign(_lowest_grade),
	_grade_to_execute(_lowest_grade) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute)
:	_name(name),
	_is_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute) {
	if (grade_to_sign < _highest_grade || grade_to_execute < _highest_grade)
		throw Form::GradeTooHighException();
	if (grade_to_sign > _lowest_grade || grade_to_execute > _lowest_grade)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
:	_name(other._name),
	_is_signed(other._is_signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute) {}

Form &Form::operator=(const Form &other) {
	if (this != &other) 
		_is_signed = other._is_signed;
	return *this;
}

Form::~Form() {}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _is_signed;
}

int Form::getGradeToSign() const {
	return _grade_to_sign;
}

int Form::getGradeToExecute() const {
	return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat &b) {
	if (_is_signed)
		throw Form::FormSignedException();
	if (b.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	_is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw () {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw () {
	return "Grade is too low";
}

const char *Form::FormSignedException::what() const throw () {
	return "Form is already signed";
}

std::ostream &operator<<(std::ostream &ostream, const Form &form) {
	ostream << "Form " << form.getName() 
	<< (form.getIsSigned() ? " is signed" : " is not signed") << std::endl
	<< "Required grade to sign is " << form.getGradeToSign() << std::endl
	<< "Required grade to sign is " << form.getGradeToExecute();
	return ostream;
}
