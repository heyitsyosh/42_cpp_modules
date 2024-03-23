#include <Bureaucrat.hpp>

# define GREEN "\033[32m"
# define RESET "\033[0m"

void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	Bureaucrat default_bureaucrat;

	std::cout << default_bureaucrat << std::endl;
}

// Testing decrementing lowest grade
void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	Bureaucrat winston("Winston Smith", 150);

	std::cout << winston << std::endl;
	try {
		winston.decrementGrade();
		std::cout << winston << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

// Testing incrementing highest grade
void test3() {
	std::cout << GREEN "[Test 3]" RESET << std::endl;
	Bureaucrat winston("Winston Smith", 1);

	std::cout << winston << std::endl;
	try {
		winston.incrementGrade();
		std::cout << winston << std::endl;
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

int main(){
	test1();
	test2();
	test3();

	return 0;
}
