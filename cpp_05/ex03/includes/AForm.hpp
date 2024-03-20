#ifndef AFORM_HPP
#define AFORM_HPP

// STL headers
#include <string>
#include <iostream> //ostream
#include <exception>

// Forward declarations
class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(const std::string &name, int grade_to_sign, int grade_to_execute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &b);
	virtual void executeInDerived() const = 0;
	void execute(const Bureaucrat &executor) const;
	class GradeTooHighException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class FormNotSignedException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
private:
	static const int highest_grade = 1;
	static const int lowest_grade = 150;
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_execute;
};

std::ostream &operator<<(std::ostream &ostream, const AForm &form);

#endif
