#include <iostream> //cerr, endl
#include <exception>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr	<< "Error: invalid arguments\n"
					<< "Usage: ./PmergeMe <positive_integers_to_sort>" << std::endl;
		return 1;
	}

	PmergeMe pm;
	try {
		pm.parseNumbers(argc, argv);
		pm.sortNumbers();
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
