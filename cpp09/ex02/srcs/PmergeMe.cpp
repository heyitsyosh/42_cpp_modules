#include <limits>
#include <ctime> //clock
#include <iostream> //cout, endl
#include <sstream>
#include <exception>
#include <algorithm> //sort
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) 
: _lst(other._lst), _vec(other._vec){}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_lst = other._lst;
		_vec = other._vec;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

int PmergeMe::parseNumber(const std::string &num_str) const {
	size_t i = 0;
	if (!num_str.empty() && num_str[0] == '+')
		i++;
	for (; i < num_str.size(); i++)
		if (num_str[i] < '0' || num_str[i] > '9')
			throw std::runtime_error(std::string(num_str) + " is not a positive integer");

	long num;
	std::istringstream ss(num_str);

	ss >> num;
	if (ss.fail() || !ss.eof()) 
		throw std::runtime_error(std::string(num_str) + " is an invalid argument");
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() )
		throw std::runtime_error(num_str + " caused integer overflow");
	return static_cast<int>(num);
}

void PmergeMe::parseNumbers(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		int num = parseNumber(std::string(argv[i]));
		_lst.push_back(num);
		_vec.push_back(num);
	}
}

void PmergeMe::printTimeTaken(
	size_t size,
	const std::string &type,
	double time) const
{
	std::cout << "Time to process a range of " << size << " elements "
		"with std::" << type << " : " << time << " us" << std::endl;
}


void PmergeMe::mergeInsertSort(std::list<int> &lst) {

}

void PmergeMe::mergeInsertSort(std::vector<int> &vec) {
	
}

void PmergeMe::sortNumbers() {
	std::cout << "Before: ";
	printContainer(_lst);

	std::clock_t start = std::clock();
	mergeInsertSort(_lst);
	std::clock_t end = std::clock();
	double time_lst = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	start = std::clock();
	mergeInsertSort(_vec);
	end = std::clock();
	double time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After: ";
	printContainer(_lst);

	printTimeTaken(_lst.size(), "lst", time_lst);
	printTimeTaken(_vec.size(), "vec", time_vec);
}

// `shuf -i 1-1000 -n 3000 | tr "\n" " " `
