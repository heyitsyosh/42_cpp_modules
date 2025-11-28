#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFoundException : public std::exception {
public:
	const char *what() const throw() {
		return ("Value not found!");
	}
};

template <typename T>
typename T::const_iterator easyfind(const T &container, int num) {
	typename T::const_iterator iter = std::find(container.begin(), container.end(), num);
	if (iter == container.end())
		throw NotFoundException();
	return iter;
}

template <typename T>
typename T::iterator easyfind(T &container, int num) {
	typename T::iterator iter = std::find(container.begin(), container.end(), num);
	if (iter == container.end())
		throw NotFoundException();
	return iter;
}

#endif
