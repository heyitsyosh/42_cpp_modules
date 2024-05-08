#include <iostream> //cout, endl
#include <limits>
#include <cctype> //isdigit, isspace
#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other): _num_stack(other._num_stack) {}
RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_num_stack = other._num_stack;
	return *this;
}
RPN::~RPN() {}

bool RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::additionOverflow(int lhs, int rhs) const {
	if ((rhs > 0 && lhs > std::numeric_limits<int>::max() - rhs)
	|| (rhs < 0 && lhs < std::numeric_limits<int>::min() - rhs))
		return true;
	return false;
}

bool RPN::subtractionOverflow(int lhs, int rhs) const {
	if ((rhs > 0 && lhs < std::numeric_limits<int>::min() + rhs)
	|| (rhs < 0 && lhs > std::numeric_limits<int>::max() + rhs))
		return true;
	return false;
}

bool RPN::multiplicationOverflow(int lhs, int rhs) const {
	int product = lhs * rhs;
	if (rhs != 0 && product / rhs != lhs)
		return true;
	return false;
}

void RPN::executeOperation(const char op) {
	if (_num_stack.size() < 2)
		throw operatorOperandMismatchException();
	const int rhs = _num_stack.top();
	_num_stack.pop();
	const int lhs = _num_stack.top();
	_num_stack.pop();
	if (op == '+') {
		if (additionOverflow(lhs, rhs))
			throw overflowException();
		_num_stack.push(lhs + rhs);
	}
	else if (op == '-') {
		if (subtractionOverflow(lhs, rhs))
			throw overflowException();
		_num_stack.push(lhs - rhs);
	}
	else if (op == '*') {
		if (multiplicationOverflow(lhs, rhs))
			throw overflowException();
		_num_stack.push(lhs * rhs);
	}
	else {
		if (rhs == 0)
			throw divisionByZeroException();
		_num_stack.push(lhs / rhs);
	}
}

int RPN::evaluateExpression(char *expr) {
	while (*expr) {
		if (std::isdigit(*expr))
			_num_stack.push(*expr - '0');
		else if (isOperator(*expr))
			executeOperation(*expr);
		else
			throw invalidExpressionException();
		expr++;
		if (*expr && !std::isspace(*expr))
			throw invalidExpressionException();
		while (std::isspace(*expr))
			expr++;
	}
	if (_num_stack.empty())
		throw emptyExpressionException();
	if (_num_stack.size() != 1)
		throw operatorOperandMismatchException();
	return _num_stack.top();
}

void RPN::run(char *expr) {
	try {
		int result = evaluateExpression((expr));
		std::cout << result << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

const char *RPN::emptyExpressionException::what() const throw() {
	return "empty expression";
}

const char *RPN::invalidExpressionException::what() const throw() {
	return "invalid expression";
}

const char *RPN::divisionByZeroException::what() const throw() {
	return "division by zero";
}

const char *RPN::overflowException::what() const throw() {
	return "overflow";
}

const char *RPN::operatorOperandMismatchException::what() const throw() {
	return "mismatching number of operators and operands";
}
