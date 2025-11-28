#include <limits>
#include "Span.hpp"

Span::Span(): _N(0), _numbers() {}
Span::Span(unsigned int N): _N(N), _numbers() {}
Span::Span(const Span &other): _N(other._N), _numbers(other._numbers) {}
Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int num) {
	if (_numbers.size() + 1 > _N)
		throw AlreadyFullException();
	_numbers.insert(num);
}

unsigned int Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw NoSpanException();
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	std::multiset<int>::iterator prev = _numbers.begin();
	std::multiset<int>::iterator current = ++_numbers.begin();
	while (current != _numbers.end()) {
		unsigned int current_span = static_cast<unsigned int>(*current - *prev);
		if (current_span < shortest)
			shortest = current_span;
		++prev;
		++current;
	}
	return shortest;
}

unsigned int Span::longestSpan() {
	if (_numbers.size() < 2)
		throw NoSpanException();
	int min = *_numbers.begin();
	int max = *--_numbers.end();
	return static_cast<unsigned int>(max - min);
}

const char *Span::AlreadyFullException::what() const throw() {
	return "Cannot add, span is already full";
}

const char *Span::NoSpanException::what() const throw() {
	return "Not enough elements for a span";
}
