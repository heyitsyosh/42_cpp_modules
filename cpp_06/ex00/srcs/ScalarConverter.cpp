#include <cctype> //isdigit, isspace, to_lower
#include <iostream> //cout, endl
#include <stdexcept> //invalid_argument, out_of_range
#include <sstream> //istringstream
#include <climits> //INT_MAX, INT_MIN, CHAR_MAX, CHAR_MIN, size_t?
#include <cfloat> //FLT_MAX, FLT_MIN, DBL_MAX, DBL_MIN
#include <cstdlib> //atoi, atof, strtod, abs
#include <cerrno> //errno, ERANGE
#include <ScalarConverter.hpp>

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

bool ScalarConverter::isChar(const std::string &str) {
	if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
	return false;
}

int ScalarConverter::toInt(const std::string &str) {
	int num = 0;
	int sign = 1;
	size_t i = 0;
	while (std::isspace(static_cast<unsigned char>(str[i])))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-')) {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			throw std::invalid_argument("");
		int digit = str[i] - '0';
		if (sign == 1 && num * 10 > INT_MAX - digit)
			throw std::out_of_range("");
		else if (sign == -1 && num * 10 < INT_MIN + digit)
			throw std::out_of_range("");
		num = (num * 10) + sign * digit;
	}
	if (num == 0 && str.find("0") == std::string::npos)
		throw std::invalid_argument("");
	return num;
}

bool ScalarConverter::isInt(const std::string &str) {
	try {
		int i = toInt(str);
		(void)i;
	} catch (const std::exception &e) {
		return false;
	}
	return true;
}

bool ScalarConverter::isPseudoLiteral(const std::string &str) {
	size_t i = 0;
	while (std::isspace(static_cast<unsigned char>(str[i])))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	std::string remainder = str.substr(i);
	for (size_t j = 0; j < remainder.length(); ++j)
		remainder[j] = std::tolower(static_cast<unsigned char>(remainder[j]));
	if (remainder == "nan" || remainder == "nanf" ||
		remainder == "inf" || remainder == "inff" || remainder == "infinity")
		return true;
	return false;
}

bool ScalarConverter::isFloat(const std::string &str) {
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
	std::istringstream iss(str);
	double num;
	iss >> num;
	if (iss.fail() || !iss.eof()) 
		return false;
	return true;
}

e_type ScalarConverter::getType(const std::string &str) {
	// testTypeValidationFuncs(str);
	if (str.empty())
		return OTHER;
	else if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isPseudoLiteral(str))
		return PSEUDOLITERAL;
	else if (isFloat(str))
		return FLOAT;
	else if (isDouble(str))
			return DOUBLE;
	return OTHER;
}

// typedef bool (*t_validationFunc)(const std::string &);

// bool testType(const std::string& str, t_validationFunc f, const std::string &type) {
// 	if (f(str)) {
// 		std::cout << str << " is " << type << std::endl;
// 		return true;
// 	}
// 	// std::cout << str << " is NOT a " << type << std::endl;
// 	return false;
// }

// void ScalarConverter::testTypeValidationFuncs(const std::string &str) {
// 	if (str.empty())
// 		std::cout << "input is empty str" << std::endl;
// 	else if (testType(str, &ScalarConverter::isChar, "char"))
// 		return;
// 	else if (testType(str, &ScalarConverter::isInt, "int"))
// 		return;
// 	else if (testType(str, &ScalarConverter::isPseudoLiteral, "pseudoliteral"))
// 		return;
// 	else if (testType(str, &ScalarConverter::isFloat, "float"))
// 		return;
// 	else if (testType(str, &ScalarConverter::isDouble, "double"))
// 		return;
// 	else
// 		std::cout << str << " is NOT any convertible type" << std::endl;
// }

void ScalarConverter::printChar(const std::string &str, e_type type) {
	if (type == OTHER || type == PSEUDOLITERAL) {
		std::cout << "impossible";
		return;
	}
	long value = 0;
	if (type == CHAR)
		value = static_cast<unsigned char>(str[0]);
	else if (type == INT)
		value = std::atoi(str.c_str());
	else if (type == FLOAT || type == DOUBLE) {
		double d = std::atof(str.c_str());
		if (d > static_cast<double>(CHAR_MAX) || d < static_cast<double>(CHAR_MIN)) {
			std::cout << "impossible";
			return;
		}
		value = static_cast<long>(d);
	}
	if (value > CHAR_MAX || value < CHAR_MIN)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<unsigned char>(value)))
		std::cout << "Non displayable";
	else {
		std::cout << "'" << static_cast<char>(value) << "'";
	}
}

void ScalarConverter::printInt(const std::string &str, e_type type) {
	if (type == OTHER || type == PSEUDOLITERAL) {
		std::cout << "impossible";
		return;
	}
	long value = 0;
	if (type == CHAR)
		value = static_cast<int>(str[0]);
	else if (type == INT)
		value = std::atoi(str.c_str());
	else if (type == FLOAT || type == DOUBLE) {
		double d = std::strtod(str.c_str(), NULL);
		if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN)) {
			std::cout << "impossible";
			return;
		}
		value = static_cast<long>(d);
	}
	std::cout << static_cast<int>(value);
}

void ScalarConverter::printFloat(const std::string &str, e_type type) {
	if (type == OTHER) {
		std::cout << "impossible";
		return;
	}
	if (type == FLOAT || type == PSEUDOLITERAL) {
		float f = std::atof(str.c_str());
		std::cout << f;
	}
	else if (type == DOUBLE) {
		double d = std::strtod(str.c_str(), NULL);
		if (d > FLT_MAX || d < -FLT_MAX) {
			std::cout << "impossible";
			return;
		}
		std::cout << d;
	}
	else {
		int value = 0;
		if (type == CHAR)
			value = static_cast<int>(str[0]);
		else if (type == INT)
			value = std::atoi(str.c_str());
		std::cout << static_cast<float>(value) << ".0";
	}
	std::cout << "f";
}

void ScalarConverter::printDouble(const std::string &str, e_type type) {
	if (type == OTHER) {
		std::cout << "impossible";
		return;
	}
	if (type == FLOAT || type == DOUBLE || type == PSEUDOLITERAL) {
		errno = 0;
		double d = std::strtod(str.c_str(), NULL);
		if (errno == ERANGE && type != PSEUDOLITERAL){
			std::cout << "impossible";
			return;
		}
		std::cout << d;
	}
	else {
		int value = 0;
		if (type == CHAR)
			value = static_cast<int>(str[0]);
		else if (type == INT)
			value = std::atoi(str.c_str());
		std::cout << static_cast<double>(value) << ".0";
	}
}

void ScalarConverter::printAllConversions(const std::string &str, e_type type) {
	std::cout << "char: " << "";
	printChar(str, type);
	std::cout << "\nint: ";
	printInt(str, type);
	std::cout << "\nfloat: ";
	printFloat(str, type);
	std::cout << "\ndouble: ";
	printDouble(str, type);
	std::endl(std::cout);
}
