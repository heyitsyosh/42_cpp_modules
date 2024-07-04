#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <string>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	void parseNumbers(int argc, char **argv);
	void sortNumbers();
private:
//	Functions
	int parseNumber(const std::string &num_str) const; 
	void printTimeTaken(
			size_t size, const std::string &type, double time) const;
	void fordJohnsonSort(std::list<int> &lst);
	void fordJohnsonSort(std::vector<int> &vec);
	std::vector<int> generateJacobsthalNumbers(int n) const;
//	Data members
	std::list<int> _lst;
	std::vector<int> _vec;
};

template <typename Container>
void printContainer(const Container &container) {
	typename Container::const_iterator it = container.begin();
	while (it != container.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

#endif
