#include <list>
#include <vector>
#include <iostream> //cout, endl
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr	<< "Error: invalid arguments\n"
					<< "Usage: ./PmergeMe <positive_integers_to_sort>" << std::endl;
		return (1);
	}

	PmergeMe pm;
	std::list<int> lst;
	std::vector<int> vec;

	try {

	}
	catch (const std::exception &e) {
		std::cerr << "Error" << e.what() << std::endl;
	}
}
