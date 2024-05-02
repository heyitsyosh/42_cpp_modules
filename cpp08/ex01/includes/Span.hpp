#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator> //distance
#include <set>

class Span {
public:
	Span();
	explicit Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int num);
	template <typename T>
	void addNumbers(const T &begin, const T &end);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	class AlreadyFullException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class NoSpanException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
private:
	unsigned int N;
	std::multiset<int> numbers;
};

template <typename T>
void Span::addNumbers(const T &begin, const T &end) {
	if (numbers.size() + std::distance(begin, end) > N)
		throw AlreadyFullException();
	for (T i = begin; i != end; i++)
		addNumber(*i);
}

#endif
