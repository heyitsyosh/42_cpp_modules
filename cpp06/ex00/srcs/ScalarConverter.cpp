#include <cctype> //isdigit
#include <iostream> //cout, endl
#include <sstream> //istringstream
#include <limits> //numeric_limits<>
#include <cfloat> //FLT_MAX, FLT_MIN, DBL_MAX, DBL_MIN
#include <cmath> //HUGE_VAL
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str) {
	e_type type = getType(str);
	printAllConversions(str, type);
}

e_type ScalarConverter::getType(const std::string &str) {
	#if DEBUG
		testTypeValidationFuncs(str);
	#endif
	if (str.empty())
		return OTHER;
	else if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
			return DOUBLE;
	return OTHER;
}

bool ScalarConverter::isChar(const std::string &str) {
	if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &str) {
	std::istringstream iss(str);
	int num;
	iss >> num;
	if (iss.fail() || !iss.eof()) 
		return false;
	return true;
}

bool ScalarConverter::isFloat(const std::string &str) {
	if (isFloatPseudoLiteral(str))
		return true;
	size_t f_pos = str.find("f");
	if (f_pos != str.length() - 1)
		return false;
	std::string str_cpy = str;
	str_cpy.erase(f_pos, 1);
	float num;
	std::istringstream iss(str_cpy);
	iss >> num;
	if (iss.fail() || !iss.eof()) 
		return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string &str) {
	if (isDoublePseudoLiteral(str))
		return true;
	std::istringstream iss(str);
	double num;
	iss >> num;
	if (iss.fail() || !iss.eof()) 
		return false;
	return true;
}

bool ScalarConverter::isDoublePseudoLiteral(const std::string &str) {
	if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf")
		return true;
	return false;
}

bool ScalarConverter::isFloatPseudoLiteral(const std::string &str) {
	if (str == "nanf" || str == "inff" || str == "-inff" || str == "+inff")
		return true;
	return false;
}

bool ScalarConverter::isPseudoLiteral(const std::string &str) {
	if (isDoublePseudoLiteral(str) || isFloatPseudoLiteral(str))
		return true;
	return false;
}

typedef bool (*t_validationFunc)(const std::string &);

static bool testType(const std::string& str, t_validationFunc f, const std::string &type) {
	if (f(str)) {
		std::cout << str << " is " << type << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::testTypeValidationFuncs(const std::string &str) {
	#if DEBUG
	if (str.empty())
		std::cout << "input is empty str" << std::endl;
	else if (testType(str, &ScalarConverter::isChar, "char"))
		return;
	else if (testType(str, &ScalarConverter::isInt, "int"))
		return;
	else if (testType(str, &ScalarConverter::isFloat, "float"))
		return;
	else if (testType(str, &ScalarConverter::isDouble, "double"))
		return;
	else
		std::cout << str << " is NOT any convertible type" << std::endl;
	#else
	(void)str;
	(void)testType;
	#endif
}

void ScalarConverter::printAllConversions(const std::string &str, e_type type) {
	if (type == CHAR)
		convertFromChar(str);
	else if (type == INT)
		convertFromInt(str);
	else if (type == FLOAT)
		convertFromFloat(str);
	else if (type == DOUBLE)
		convertFromDouble(str);
	else
		convertFromOther();
}

void ScalarConverter::convertFromChar(const std::string &str) {
	char c = str[0];

	printChar(static_cast<unsigned char>(str[0]));
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(const std::string &str) {
	std::istringstream iss(str);
	int i;
	iss >> i;

	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		std::cout << "char: Impossible" << std::endl;
	else
		printChar(static_cast<unsigned char>(i));
	printInt(i);
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
}

// static bool isInf(double x) {
//     return (x == HUGE_VAL || x == -HUGE_VAL);
// }

// static bool isNaN(double x) {
//     return x != x;
// }

void ScalarConverter::convertFromFloat(const std::string &str) {
	std::istringstream iss(str);
	float f;
	iss >> f;

	if  (isPseudoLiteral(str)) {
		std::cout << "char: Impossible\nint: Impossible\n";
		std::cout << "float: " << str << "\n";
		std::string str_cpy = str;
		str_cpy = str_cpy.erase(str_cpy.size() - 1); 
		std::cout << "double: " << str_cpy << std::endl;
		return;
	}
	if (f > static_cast<float>(std::numeric_limits<char>::max())
		|| f < static_cast<float>(std::numeric_limits<char>::min()))
		std::cout << "char: Impossible" << std::endl;
	else
		printChar(static_cast<unsigned char>(f));
	if (f > static_cast<float>(std::numeric_limits<int>::max())
		|| f < static_cast<float>(std::numeric_limits<int>::min()))
		std::cout << "int: Impossible" << std::endl;
	else
		printInt(static_cast<int>(f));
	printFloat(f);
	printDouble(static_cast<double>(f));
}

void ScalarConverter::convertFromDouble(const std::string &str) {
	std::istringstream iss(str);
	double d;
	iss >> d;

	if  (isPseudoLiteral(str)) {
		std::cout << "char: Impossible\nint: Impossible\n";
		std::cout << "float: " << str << "f\n";
		std::cout << "double: " << str << std::endl;
		return;
	}
	if (d > static_cast<double>(std::numeric_limits<char>::max())
		|| d < static_cast<double>(std::numeric_limits<char>::min()))
		std::cout << "char: Impossible" << std::endl;
	else
		printChar(static_cast<unsigned char>(d));
	if (d > static_cast<double>(std::numeric_limits<int>::max())
		|| d < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: Impossible" << std::endl;
	else
		printInt(static_cast<int>(d));
	if (d > static_cast<double>(std::numeric_limits<float>::max())
		|| d < -static_cast<double>(std::numeric_limits<float>::max())
		|| (d > 0 && d < static_cast<double>(std::numeric_limits<float>::min()))
		|| (d < 0 && d > -static_cast<double>(std::numeric_limits<float>::min())))
		std::cout << "float: Impossible" << std::endl;
	else
		printFloat(static_cast<float>(d));
	printDouble(d);
}

void ScalarConverter::convertFromOther() {
	std::cout << "char: Impossible\n"
		<< "int: Impossible\n"
		<< "float: Impossible\n"
		<< "double: Impossible" << std::endl;
}

void ScalarConverter::printChar(unsigned char c) {
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
}

void ScalarConverter::printInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) {
	std::cout << "float: " << f;
	if (f - static_cast<int>(f) == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: " << d;
	if (d - static_cast<int>(d) == 0)
		std::cout << ".0";
	std::endl(std::cout);
}
