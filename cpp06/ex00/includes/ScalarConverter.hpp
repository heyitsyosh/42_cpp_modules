#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	OTHER
};

class ScalarConverter {
public:
	static void convert(const std::string &str);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	static bool isChar(const std::string &str);
	static int toInt(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isFloat(const std::string &str);
	static bool isDouble(const std::string &str);
	static bool isPseudoLiteral(const std::string &str);
	static bool isDoublePseudoLiteral(const std::string &str);
	static bool isFloatPseudoLiteral(const std::string &str);
	static e_type getType(const std::string &str);
	static void convertFromChar(const std::string &str);
	static void convertFromInt(const std::string &str);
	static void convertFromFloat(const std::string &str);
	static void convertFromDouble(const std::string &str);
	static void convertFromOther();
	static void printChar(unsigned char c);
	static void printInt(int i);
	static void printFloat(float f);
	static void printDouble(double d);
	static void printAllConversions(const std::string &str, e_type type);
	static void testTypeValidationFuncs(const std::string &str);
};

#endif
