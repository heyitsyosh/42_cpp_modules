#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <ctime> //tm, strftime

#ifndef PATH_TO_DATA
#define PATH_TO_DATA "data/data.csv"
#endif

typedef struct s_date {
	int day;
	int month;
	int year;
} t_date;

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();
	void processPriceDatabase();
	// void processInputFile(const std::string &filename);
	void exchangeAndOutput();
private:
	std::map<t_date, double> _data;
	std::map<int, double> _input;
	void validateFirstLine(
			const std::string &line, const std::string &str, const std::string &file) const;
	void invalidFormatErr(int idx) const;
	t_date parseDate(const std::string &date_str);
	double parsePrice(const std::string &price);
};

#endif
