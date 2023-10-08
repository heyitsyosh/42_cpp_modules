#include "Harl.hpp"
#include <iostream> //cout, endl

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <filter_level>" << std::endl;
		return (1);
	}
	Harl harl;
	harl.complain(argv[1]);
}
