#include <iostream> //cout, endl
#include <cstdlib> //rand, srand, NULL
#include <ctime> //time
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int n = rand() % 3;
	switch (n) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return NULL;
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Error: unknown object type";
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
		return;
	}
	catch (const std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
		return;
	}
	catch (const std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
	}
	catch (const std::exception &e) {
		std::cout << "Error: unknown type";
	}
}

int main() {
	std::srand(std::time(NULL));

	Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	std::cout << ", ";
	identify(ref);
	delete ptr;
	return 0;
}
