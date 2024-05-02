#include <iostream> //cout, endl
#include <string>
#include <vector>
#include <list>
#include "easyfind.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

void testList() {
	std::cout << GREEN "[Test (List ver.)]" RESET << std::endl;
	std::list<int> lst;

	for (size_t i = 0; i < 3; i++)
		lst.push_back(i);
	try {
		for (size_t i = 0; i < 5; i++) {
			std::cout << "Searching for " << i << ", ";
			std::list<int>::iterator searchResult = easyfind(lst, i);
			std::cout << "found " << *searchResult << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void testVector() {
	std::cout << GREEN "[Test (Map ver.)]" RESET << std::endl;
	std::vector<int> vec;

	for (size_t i = 0; i < 3; i++)
		vec.push_back(i);
	try {
		for (size_t i = 0; i < 5; i++) {
			std::cout << "Searching for " << i << ", ";
			std::vector<int>::iterator searchResult = easyfind(vec, i);
			std::cout << "found " << *searchResult << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void testConstVector() {
	std::cout << GREEN "[Test (Const Vector ver.)]" RESET << std::endl;
	int values[] = {0, 1, 2};
	const std::vector<int> vec(values, values + sizeof(values) / sizeof(values[0]));

	try {
		for (int i = 0; i < 5; i++) {
			std::cout << "Searching for " << i << ": ";
			std::vector<int>::const_iterator searchResult = easyfind(vec, i);
			std::cout << "found " << *searchResult << std::endl;
		}
	}
	catch (const NotFoundException& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	testList();
	testVector();
	testConstVector();

	return 0;
}
