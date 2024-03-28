#ifndef FORM_HPP
#define FORM_HPP

// STL headers
#include <string>
#include <iostream> //ostream, (cout, endl)
#include <exception>

// Forward declarations
class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &b);
	class GradeTooHighException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class FormSignedException: public std::exception {
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

std::ostream &operator<<(std::ostream &ostream, const Form &form);

#endif
