#include <limits>
#include "Span.hpp"

Span::Span(): N(0), numbers() {}
Span::Span(unsigned int N): N(N), numbers() {}
Span::Span(const Span &other): N(other.N), numbers(other.numbers) {}
Span &Span::operator=(const Span &other) {
	if (this != &other) {
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int num) {
	if (numbers.size() + 1 > N)
		throw AlreadyFullException();
	numbers.insert(num);
}

unsigned int Span::shortestSpan() {
	if (numbers.size() < 2)
		throw NoSpanException();
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	std::multiset<int>::iterator prev = numbers.begin();
	std::multiset<int>::iterator current = ++numbers.begin();
	while (current != numbers.end()) {
		unsigned int current_span = static_cast<unsigned int>(*current - *prev);
		if (current_span < shortest)
			shortest = current_span;
		++prev;
		++current;
	}
	return shortest;
}

unsigned int Span::longestSpan() {
	if (numbers.size() < 2)
		throw NoSpanException();
	int min = *numbers.begin();
	int max = *--numbers.end();
	return static_cast<unsigned int>(max - min);
}

const char *Span::AlreadyFullException::what() const throw() {
	return "Cannot add, span is already full";
}

const char *Span::NoSpanException::what() const throw() {
	return "Not enough elements for a span";
}
