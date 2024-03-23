#include <iostream> //cout, endl
#include <Harl.hpp>

# define LEVELS 4

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() const {
	std::cout <<	"[ DEBUG ]\n"
					"I love having extra bacon for my "
					"7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
					"I really do!\n\n";
}

void Harl::info() const {
	std::cout <<	"[ INFO ]\n"
					"I cannot believe adding extra bacon costs more money.\n"
					"You didn't put enough bacon in my burger!\n"
					"If you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning() const {
	std::cout <<	"[ WARNING ]\n"
					"I think I deserve to have some extra bacon for free.\n"
					"I've been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error() const {
	std::cout <<	"[ ERROR ]\n"
					"This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) const {
	std::string levels[LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i <= LEVELS) {
		if (level == levels[i])
			break ;
		i++;
	}

	while (1) {
		switch(i) {
			case 0:
				debug();
				break ;
			case 1:
				info();
				break ;
			case 2:
				warning();
				break ;
			case 3:
				error();
				return ;
			default :
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				return;
		}
		i++;
	}
}
