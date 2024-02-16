#include "Bureaucrat.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	Bureaucrat standard_bureaucrat;

	std::cout << standard_bureaucrat << std::endl;
}

void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	Bureaucrat winston("Winston Smith", LOWEST_GRADE);

	std::cout << winston << std::endl;
	try {
		winston.decrementGrade();
		std::cout << winston << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

void test3() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	Bureaucrat winston("Winston Smith", HIGHEST_GRADE);

	std::cout << winston << std::endl;
	try {
		winston.incrementGrade();
		std::cout << winston << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}

int main(){
	test1();
	test2();
	test3();

	return 0;
}
