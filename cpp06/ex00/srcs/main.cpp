#include <iostream> //cout, endl
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: <scalar_type_to_convert>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);

	return 0;
}
