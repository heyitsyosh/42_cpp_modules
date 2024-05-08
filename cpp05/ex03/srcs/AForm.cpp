#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
:	_name("Default"),
	_is_signed(false),
	_grade_to_sign(_lowest_grade),
	_grade_to_execute(_lowest_grade) {}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute)
:	_name(name),
	_is_signed(false),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute) {
	if (grade_to_sign < _highest_grade || grade_to_execute < _highest_grade)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > _lowest_grade || grade_to_execute > _lowest_grade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
:	_name(other._name),
	_is_signed(other._is_signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) 
		_is_signed = other._is_signed;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _is_signed;
}

int AForm::getGradeToSign() const {
	return _grade_to_sign;
}

int AForm::getGradeToExecute() const {
	return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (_is_signed)
		throw AForm::FormSignedException();
	if (b.getGrade() > _grade_to_sign)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}

void AForm::execute(const Bureaucrat &b) const {
	if (_is_signed == false)
		throw AForm::FormNotSignedException();
	if (b.getGrade() > _grade_to_execute)
		throw AForm::GradeTooLowException();
	executeInDerived();
}

const char *AForm::GradeTooHighException::what() const throw () {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw () {
	return "Grade is too low";
}

const char *AForm::FormSignedException::what() const throw () {
	return "Form is already signed";
}

const char *AForm::FormNotSignedException::what() const throw () {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &ostream, const AForm &form) {
	ostream << "Form " << form.getName() 
	<< (form.getIsSigned() ? " is signed" : " is not signed") << std::endl
	<< "Required grade to sign is " << form.getGradeToSign() << std::endl
	<< "Required grade to execute is " << form.getGradeToExecute();
	return ostream;
}
