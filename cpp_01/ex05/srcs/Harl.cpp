#include <iostream> //cout
#include <Harl.hpp>

# define LEVELS 4

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() const {
	std::cout <<	"I love having extra bacon for my "
					"7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
					"I really do!\n";
}

void Harl::info() const {
	std::cout <<	"I cannot believe adding extra bacon costs more money.\n"
					"You didn't put enough bacon in my burger!\n"
					"If you did, I wouldn't be asking for more!\n";
}

void Harl::warning() const {
	std::cout <<	"I think I deserve to have some extra bacon for free.\n"
					"I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error() const {
	std::cout <<	"This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) const {
	std::string levels[LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[LEVELS])() const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < LEVELS; i++)
		if (level == levels[i])
			(this->*funcs[i])();
}
