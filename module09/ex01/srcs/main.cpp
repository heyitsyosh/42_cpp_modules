#include <iostream> //cerr, endl
#include "RPN.hpp"

int main (int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Error: invalid arguments" << std::endl;
	else {
		RPN calculator;
		calculator.run(argv[1]);
	}
	return 0;
}
