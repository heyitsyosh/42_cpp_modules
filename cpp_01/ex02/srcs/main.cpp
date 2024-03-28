#include <iostream> //cout, endl
#include <string>

int main() {
	std::string stringVar = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVar;
	std::string &stringREF = stringVar;

	std::cout << "Address from original var:\t" << &stringVar << std::endl;
	std::cout << "Address from pointer:\t\t" << stringPTR << std::endl;
	std::cout << "Address from reference:\t\t" << &stringREF << std::endl;

	std::cout << "Value from original var:\t" << stringVar << std::endl;
	std::cout << "Value from pointer:\t\t" << *stringPTR << std::endl;
	std::cout << "Value from reference:\t\t" << stringREF << std::endl;
}
