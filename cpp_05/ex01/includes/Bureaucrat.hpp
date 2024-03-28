#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// STL headers
#include <string>
#include <iostream> //ostream, (cout, endl)
#include <exception>

// Forward declarations
class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form) const;
	class GradeTooHighException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
private:
	static const int highest_grade = 1;
	static const int lowest_grade = 150;
	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif
