#include <iostream> //cerr, endl
#include <exception>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./btc <path_to_input_file>" << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	try {
		btc.processPriceDatabase();
		btc.processInputFile(argv[1]);
		btc.exchangeAndOutput();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
