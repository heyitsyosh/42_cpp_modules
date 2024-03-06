#include "Bureaucrat.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

// Testing
void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
}

// Testing 
void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
}

// Testing
void test3() {
	std::cout << GREEN "[Test 3]" RESET << std::endl;
}

int main(){
	test1();
	test2();
	test3();

	return 0;
}
