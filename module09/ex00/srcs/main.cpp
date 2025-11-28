#include <iostream> //cerr, endl
#include <exception>
#include "BitcoinExchange.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <path_to_input_file>" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	try {
		btc.processPriceDatabase();
		btc.exchangeInput(argv[1]);
	}
	catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << "." RESET << std::endl;
		return 1;
	}
	return 0;
}
