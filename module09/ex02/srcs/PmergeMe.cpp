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

std::vector<int> PmergeMe::generateJacobsthalNumbers(int n) const {
	std::vector<int> jacobsthal(n);
	if (n > 0)
		jacobsthal[0] = 0;
	if (n > 1)
		jacobsthal[1] = 1;
	for (int i = 2; i < n; ++i)
		jacobsthal[i] = jacobsthal[i-1] + 2 * jacobsthal[i-2];
	return jacobsthal;
}

void PmergeMe::fordJohnsonSort(std::list<int> &lst) {
	if (lst.size() < 2)
		return;

	std::list<int> larger, smaller;
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end()) {
		int first = *it;
		++it;
		if (it == lst.end()) {
			larger.push_back(first);
			break;
		}
		int second = *it;
		++it;
		if (first > second) {
			larger.push_back(first);
			smaller.push_back(second);
		}
		else {
			larger.push_back(second);
			smaller.push_back(first);
		}
	}
	fordJohnsonSort(larger);

	std::vector<int> jacobsthal = generateJacobsthalNumbers(larger.size() + smaller.size());

	for (std::list<int>::iterator small_it = smaller.begin(); small_it != smaller.end(); ++small_it) {
		std::list<int>::iterator pos = larger.begin();
			for (size_t i = 0; i < jacobsthal.size() && pos != larger.end(); ++i) {
				if (*small_it < *pos) {
					break;
			}
			++pos;
		}
		larger.insert(pos, *small_it);
	}

	lst = larger;
}

void PmergeMe::fordJohnsonSort(std::vector<int> &vec) {
	if (vec.size() < 2)
		return;

	std::vector<int> larger, smaller;
	for (size_t i = 0; i < vec.size(); i += 2) {
		if (i + 1 < vec.size()) {
			int first = vec[i];
			int second = vec[i + 1];
			if (first > second) {
				larger.push_back(first);
				smaller.push_back(second);
			} else {
				larger.push_back(second);
				smaller.push_back(first);
			}
		}
		else
			larger.push_back(vec[i]);
	}
	fordJohnsonSort(larger);

	std::vector<int> jacobsthal = generateJacobsthalNumbers(larger.size() + smaller.size());

	for (std::vector<int>::iterator small_it = smaller.begin(); small_it != smaller.end(); ++small_it) {
		std::vector<int>::iterator pos = larger.begin();
		for (size_t i = 0; i < jacobsthal.size() && pos != larger.end(); ++i) {
			if (*small_it < *pos) {
				break;
			}
			++pos;
		}
		larger.insert(pos, *small_it);
	}
	vec = larger;
}

void PmergeMe::sortNumbers() {
	std::cout << "Before: ";
	printContainer(_lst);

	std::clock_t start = std::clock();
	fordJohnsonSort(_lst);
	std::clock_t end = std::clock();
	double time_lst = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	start = std::clock();
	fordJohnsonSort(_vec);
	end = std::clock();
	double time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Sorted list: ";
	printContainer(_lst);
	std::cout << "Sorted vector: ";
	printContainer(_vec);

	printTimeTaken(_lst.size(), "lst", time_lst);
	printTimeTaken(_vec.size(), "vec", time_vec);
}
