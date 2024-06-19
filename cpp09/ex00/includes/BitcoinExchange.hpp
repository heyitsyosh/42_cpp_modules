#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime> //tm, strftime
#include <string>

#ifndef PATH_TO_DATA
#define PATH_TO_DATA "data/data.csv"
#endif

typedef struct s_date {
	int day;
	int month;
	int year;
} t_date;

struct compareDate;

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
	std::map<t_date, double, bool (*)(const t_date&, const t_date&)> _data;
	std::map<int, double> _input;
	bool strIsNumberic(const std::string &date_str) const;
	void validateFirstLine(
			const std::string &line, const std::string &str, const std::string &file) const;
	bool validateDate(const t_date &date) const;
	void invalidFormatErr(int idx) const;
	t_date parseDate(const std::string &date_str, int idx) const ;
	double parsePrice(const std::string &price_str, int idx) const ;
};

#endif
