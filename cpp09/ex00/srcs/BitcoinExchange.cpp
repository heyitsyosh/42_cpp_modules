#include <cctype> //isdigit
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <exception>
#include "BitcoinExchange.hpp"

static bool compareDates(const t_date &lhs, const t_date &rhs) {
	if (lhs.year != rhs.year)
		return lhs.year < rhs.year;
	if (lhs.month != rhs.month)
		return lhs.month < rhs.month;
	return lhs.day < rhs.day;
}

BitcoinExchange::BitcoinExchange(): _data(compareDates) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: _data(compareDates), _input(other._input) {
	_data = other._data;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = std::map<t_date, double, bool (*)(const t_date&, const t_date&)>(compareDates);
		_data = other._data;
		_input = other._input;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::invalidFormatErr(int idx) const {
	std::ostringstream error_msg;
	error_msg << "Error: invalid format detected at line " << idx << " in " << PATH_TO_DATA;
	throw std::runtime_error(error_msg.str());
}

void BitcoinExchange::validateFirstLine(
	const std::string &line,
	const std::string &str,
	const std::string &file) const
{
	if (line != str) {
		throw std::runtime_error(
			"Error: invalid format detected\n       "
			"first line of "+ file + " should be \"" + str + "\"");
	}
}

bool BitcoinExchange::validateDate(const t_date &date) const {
	if (date.year < 0 || date.year > 9999 || date.month < 1 || date.month > 12)
		return false;

	static const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int max_day = days_in_month[date.month - 1];
	return date.day <= max_day;
}

bool BitcoinExchange::strIsNumberic(const std::string &str) const {
	std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isdigit(*it))
		++it;
    return !str.empty() && it == str.end();
}

t_date BitcoinExchange::parseDate(const std::string &date_str, int idx) const {
	if (date_str.size() != 10 
		|| !strIsNumberic(date_str.substr(0, 4)) 
		|| !strIsNumberic(date_str.substr(5, 2)) 
		|| !strIsNumberic(date_str.substr(8, 2)))
		invalidFormatErr(idx);

	t_date date;
	char dash1, dash2;
	std::istringstream ss(date_str);
	ss >> date.year >> dash1 >> date.month >> dash2 >> date.day;

	if (ss.fail() || dash1 != '-' || dash2 != '-' || !validateDate(date)
		|| ss.peek() != std::istringstream::traits_type::eof())
		invalidFormatErr(idx);
	return date;
}
#include <iostream>
double BitcoinExchange::parsePrice(const std::string &price_str, int idx) const {
	double price;
	std::istringstream ss(price_str);
	ss >> price;
	if (ss.fail() || ss.peek() != std::istringstream::traits_type::eof() 
		|| (price_str[0] != '.' && !std::isdigit(price_str[0])))
		invalidFormatErr(idx);
	return price;
}

void BitcoinExchange::processPriceDatabase() {
	std::ifstream database(PATH_TO_DATA, std::ios_base::in);
	if (!database.is_open())
		throw std::runtime_error(std::string("Error: could not open file ") + PATH_TO_DATA);

	std::string line, date, price;

	std::getline(database, line);
	validateFirstLine(line, "date,exchange_rate", PATH_TO_DATA);

	int idx = 1;
	while (std::getline(database, line)) {
		if (line.empty())
			break;
		idx++;
		std::istringstream ln(line);
		if (!std::getline(ln, date, ',') || !std::getline(ln, price))
			invalidFormatErr(idx);
		_data[parseDate(date, idx)] = parsePrice(price, idx);
	}
	database.close();
}

// void BitcoinExchange::processInputFile(const std::string &filename) {
// 	std::ifstream input(filename, std::ios_base::in);
// 	if (!input.is_open())
// 		throw std::runtime_error("Error: could not open file" + filename);

// 	std::string line;
// 	std::getline(input, line);
// 	validateFirstLine(line, "date | value", filename);

// 	int line_number = 1;
// 	while (std::getline(input, line)) {
		
// 	}
// 	input.close();
// }

void BitcoinExchange::exchangeAndOutput() {

}

// Error: not a positive number
// Error: bad input => 2001-42-42
// Error: too large a number.
