#include "iter.hpp"
#include <iostream> //cout

# define GREEN "\033[32m"
# define RESET "\033[0m"

void increment_int(int& i) {
    ++i;
}

void print_int(const int& i) {
    std::cout << i << ' ';
}

void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	int nums[] = {1, 2, 3, 4, 5};
	const size_t length = sizeof(nums) / sizeof(nums[0]);

	std::cout << "Printing non-const elements: ";
	iter(nums, length, print_int);
	std::endl(std::cout);

    std::cout << "Incrementing elements: ";
    iter(nums, length, increment_int);
	iter(nums, length, print_int);
	std::endl(std::cout);
}

void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
    int const_nums[] = {1, 2, 3, 4, 5};
	const size_t length = sizeof(const_nums) / sizeof(const_nums[0]);

    std::cout << "Printing const elements: ";
    iter(const_nums, length, print_int);
}

int main() {
	test1();
	test2();

    return 0;
}
