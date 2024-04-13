#include "Bureaucrat.hpp"
#include "Form.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

// Testing Form insertion overload
void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	Form defualt_form;

	std::cout << defualt_form << std::endl;
}

// Testing Form constructor exception handling
void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	try {
		Form invalid_form("Invalid Form", 0, 150);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

// Testing beSigned exception handling
void test3() {
	std::cout << GREEN "[Test 3]" RESET << std::endl;
	Form mid_setting_form("Mid-Setting-Form", 75, 150);
	Bureaucrat lowly_b("Lowly Bureaucrat", 150);
	Bureaucrat insufficient_b("Insufficient Bureaucrat", 76);
	Bureaucrat sufficient_b("Sufficient Bureaucrat", 75);
	Bureaucrat superior_b("Superior Bureaucrat", 1);

	lowly_b.signForm(mid_setting_form);
	insufficient_b.signForm(mid_setting_form);
	sufficient_b.signForm(mid_setting_form);
	superior_b.signForm(mid_setting_form);
}

int main(){
	test1();
	test2();
	test3();

	return 0;
}
