#include <iostream> //cout, cerr, endl
#include <limits>
#include <vector>
#include "Span.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	std::vector<int> vec;
	const unsigned int N = 10001;
	Span sp(N);

	for (unsigned int i = 0; i < N; i++)
		vec.push_back(i);
	std::cout << "Vector with elements for span has size of " << vec.size() << ".\n";
	sp.addNumbers(vec.begin(), vec.end());
	std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
}

void test3(void) {
	std::cout << GREEN "[Test 3]" RESET << std::endl;
	Span sp = Span(3);

	std::cout << "Span elements are [INT_MAX, INT_MIN].\n";
	sp.addNumber(std::numeric_limits<int>::max());
	sp.addNumber(std::numeric_limits<int>::min());
	std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan: " << sp.longestSpan() << "\n";
	sp.addNumber(0);
	std::cout << "Span elements are [INT_MAX, INT_MIN, 0].\n";
	std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
}

void test4() {
	std::cout << GREEN "[Test 3]" RESET << std::endl;
	Span sp = Span(1);

	try {
		std::cout << "Adding 2 numbers to a span of size 1..\n";
		sp.addNumber(0);
		sp.addNumber(0);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		std::cout << "Calculating shortest span from a span with 1 number...\n";
		std::cout << sp.shortestSpan() << "\n";
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main() {
	test1();
	test2();
	test3();
	test4();

	return 0;
}
