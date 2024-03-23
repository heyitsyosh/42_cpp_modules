#include <AForm.hpp>
#include <Bureaucrat.hpp>

AForm::AForm()
:	name("Default"),
	is_signed(false),
	grade_to_sign(lowest_grade),
	grade_to_execute(lowest_grade) {}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute)
:	name(name),
	is_signed(false),
	grade_to_sign(grade_to_sign),
	grade_to_execute(grade_to_execute) {
	if (grade_to_sign < highest_grade)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > lowest_grade)
		throw AForm::GradeTooLowException();
	if (grade_to_execute < highest_grade)
		throw AForm::GradeTooHighException();
	if (grade_to_execute > lowest_grade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
:	name(other.name),
	is_signed(other.is_signed),
	grade_to_sign(other.grade_to_sign),
	grade_to_execute(other.grade_to_execute) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) 
		is_signed = other.is_signed;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return is_signed;
}

int AForm::getGradeToSign() const {
	return grade_to_sign;
}

int AForm::getGradeToExecute() const {
	return grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (is_signed)
		throw AForm::FormSignedException();
	if (b.getGrade() > grade_to_sign)
		throw AForm::GradeTooLowException();
	is_signed = true;
}

void AForm::execute(const Bureaucrat &b) const {
	if (is_signed == false)
		throw AForm::FormNotSignedException();
	if (b.getGrade() > grade_to_execute)
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
