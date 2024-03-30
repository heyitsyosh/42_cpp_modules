#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	OTHER
};

class ScalarConverter {
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	static void convert(const std::string &str);
private:
	static bool isChar(const std::string &str);
	static int toInt(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isFloat(const std::string &str);
	static bool isDouble(const std::string &str);
	static bool isPseudoLiteral(const std::string &str);
	static e_type getType(const std::string &str);
	static void printChar(const std::string &str, e_type type);
	static void printInt(const std::string &str, e_type type);
	static void printFloat(const std::string &str, e_type type);
	static void printDouble(const std::string &str, e_type type);
	static void printAllConversions(const std::string &str, e_type type);
	static void testTypeValidationFuncs(const std::string &str);
};

#endif
