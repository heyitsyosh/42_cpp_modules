#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// STL headers
#include <string>
#include <exception>
#include <iostream> //ostream, (cout, cerr, endl)

// Forward declarations
class AForm;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form) const;
	void executeForm(const AForm &form) const;
	class GradeTooHighException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
private:
	static const int _highest_grade = 1;
	static const int _lowest_grade = 150;
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif
