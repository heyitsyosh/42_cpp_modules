#include <fstream> //ifstream
#include <sstream> //istringstream
#include <exception>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: _data(other._data), _input(other._input){}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = other._data;
		_input = other._input;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

t_date parseDate(const std::string &date_str) {
	t_date ret;
	std::istringstream ss(date_str);
	if (!validateDate)
		throw std::runtime_error("Error: invalid format detected");
	return ret;
}

double parsePrice(const std::string &price) {

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

void BitcoinExchange::invalidFormatErr(int idx) const {
	std::ostringstream error_msg;
	error_msg << "Error: invalid format detected at line " << idx;
	throw std::runtime_error(error_msg.str());
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
		_data[parseDate(date)] = parsePrice(price);
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

// Error: not a positive number.
// Error: bad input => 2001-42-42
// Error: too large a number.
