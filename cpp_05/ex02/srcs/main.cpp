#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

# define GREEN "\033[32m"
# define RESET "\033[0m"

void testForm(Bureaucrat &b, AForm &f) {
	b.signForm(f);
	b.executeForm(f);
}

// Testing ShrubberyCreationForm execution
// Grade to sign: 145, Grade to execute: 137
void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	Bureaucrat signatory_b("Signatory Bureaucrat", 145);
	Bureaucrat executor_b("Executor Bureaucrat", 137);
	ShrubberyCreationForm scf("person");

	testForm(signatory_b, scf);
	std::endl(std::cout);
	testForm(executor_b, scf);
}

// Testing RobotomyRequestForm execution
// Grade to sign: 72, Grade to execute: 45
void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	Bureaucrat signatory_b("Signatory Bureaucrat", 72);
	Bureaucrat executor_b("Executor Bureaucrat", 45);
	RobotomyRequestForm rrf("person");

	testForm(signatory_b, rrf);
	std::endl(std::cout);
	testForm(executor_b, rrf);
}

// Testing PresidentialPardonForm execution
// Grade to sign: 25, Grade to execute: 5
void test3() {
	std::cout << GREEN "[Test 3]" RESET << std::endl;
	Bureaucrat signatory_b("Signatory Bureaucrat", 25);
	Bureaucrat executor_b("Executor Bureaucrat", 5);
	PresidentialPardonForm ppf("person");

	testForm(signatory_b, ppf);
	std::endl(std::cout);
	testForm(executor_b, ppf);
}

int main(){
	test1();
	test2();
	test3();

	return 0;
}
