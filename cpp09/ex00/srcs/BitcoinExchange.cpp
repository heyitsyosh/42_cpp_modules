#include <cctype> //isdigit
#include <limits>
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <iostream> //cout, cerr
#include <exception>
#include "BitcoinExchange.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

static bool compareDates(const t_date &lhs, const t_date &rhs) {
	if (lhs.year != rhs.year)
		return lhs.year < rhs.year;
	if (lhs.month != rhs.month)
		return lhs.month < rhs.month;
	return lhs.day < rhs.day;
}

bool s_date::operator==(const s_date &other) const {
	return year == other.year && month == other.month && day == other.day;
}

bool s_date::operator!=(const s_date &other) const {
	return !(*this == other);
}

BitcoinExchange::BitcoinExchange(): _data(compareDates) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _data(compareDates) {
	_data = other._data;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_data = std::map<t_date, double, bool (*)(const t_date&, const t_date&)>(compareDates);
		_data = other._data;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::invalidFormatErr(int idx) const {
	std::ostringstream error_msg;
	error_msg << RED "invalid format detected at line " << idx << " in " << PATH_TO_DATA RESET;
	throw std::runtime_error(error_msg.str());
}

void BitcoinExchange::validateFirstLine(
	const std::string &line,
	const std::string &str,
	const std::string &file) const
{
	if (line != str) {
		throw std::runtime_error(
			"invalid format detected.\n       "
			"first line of "+ file + " must be \"" + str + "\"");
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

double BitcoinExchange::parsePrice(const std::string &price_str, int idx) const {
	double price;
	std::istringstream ss(price_str);
	ss >> price;
	if (ss.fail() || ss.peek() != std::istringstream::traits_type::eof() || price < 0.0
		|| (price_str[0] != '.' && !std::isdigit(price_str[0])))
		invalidFormatErr(idx);
	return price;
}

void BitcoinExchange::processPriceDatabase() {
	std::ifstream database(PATH_TO_DATA, std::ios_base::in);
	if (!database.is_open())
		throw std::runtime_error(std::string("could not open file ") + PATH_TO_DATA);

	std::string line;
	std::getline(database, line);
	validateFirstLine(line, "date,exchange_rate", PATH_TO_DATA);

	int idx = 1;
	while (std::getline(database, line)) {
		if (line.empty())
			break;
		idx++;
		std::string date, price;
		std::istringstream ln(line);
		if (!std::getline(ln, date, ',') || !std::getline(ln, price))
			invalidFormatErr(idx);
		_data[parseDate(date, idx)] = parsePrice(price, idx);
	}
	database.close();
}

double BitcoinExchange::getRate(std::string date_str) const {
	if (!date_str.empty())
		date_str.erase(date_str.size() - 1);
	t_date date;
	try {
		date = parseDate(date_str, 0);
		std::map<t_date, double, bool (*)(const t_date&, const t_date&)>::const_iterator it;
		it = _data.lower_bound(date);
		if (it == _data.end() || (it != _data.begin() && it->first != date))
			--it;
		return it->second;
	}
	catch (const std::exception &e) {
		throw std::runtime_error("bad date input => " + date_str);
	}
	return 0.0;
}

double BitcoinExchange::getResult(double rate, std::string amount_str) const {
	if (amount_str.empty())
		throw std::runtime_error("bad amount input => " + amount_str);
	amount_str.erase(amount_str.begin());
	double amount;
	std::istringstream ss(amount_str);
	ss >> amount;
	if (ss.fail() || ss.peek() != std::istringstream::traits_type::eof() || amount < 0)
		throw std::runtime_error("not a positive number");
	if (amount > std::numeric_limits<int>::max())
		throw std::runtime_error("too large a number");
	if (rate != 0 && amount > std::numeric_limits<double>::max() / rate)
		throw std::runtime_error("overflow detected during exchange calutation");
	return rate * amount;
}

void BitcoinExchange::exchangeInput(const std::string &filename) {
	std::ifstream input(filename.c_str(), std::ios_base::in);
	if (!input.is_open())
		throw std::runtime_error("could not open file" + filename);

	std::string line;
	std::getline(input, line);
	validateFirstLine(line, "date | value", filename);

	while (std::getline(input, line)) {
		try {
			std::string date, amount;
			std::istringstream ln(line);
			if (!std::getline(ln, date, '|') || !std::getline(ln, amount))
				throw std::runtime_error("bad input => " + line);
			double rate = getRate(date);
			double result = getResult(rate, amount);
			std::cout << date << "=>" << amount << " = " << result << std::endl;
		}
		catch (const std::exception &e) {
			std::cerr << RED "Error: " << e.what() << "." RESET << std::endl;
			continue;
		}
	}
	input.close();
}
