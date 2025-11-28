#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <string>
#include <stack>

class RPN {
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	void run(char *expr);
private:
//	Functions
	bool isOperator (char c) const;
	int evaluateExpression(char *expr);
	void executeOperation(const char op);
	bool additionOverflow(int lhs, int rhs) const;
	bool subtractionOverflow(int lhs, int rhs) const;
	bool multiplicationOverflow(int lhs, int rhs) const;
//	Data members
	std::stack<int> _num_stack;
//	Exception classes
	class emptyExpressionException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class invalidExpressionException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class divisionByZeroException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class overflowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class operatorOperandMismatchException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif
