#include <iostream> //cout, cin, endl
#include <cstdlib> //exit, EXIT_FAILURE
#include <iomanip> //setw, right
#include "Contact.hpp"

#define WIDTH 10

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getField(const std::string &field_type) {
	std::string input;
	bool valid_input_entered = false;
	while (!valid_input_entered)
	{
		std::cout << "Enter " << field_type << ": ";
		if (!std::getline(std::cin, input))
			std::exit(EXIT_FAILURE);
		if (!input.empty())
			valid_input_entered = true;
		else
			std::cout << "Invalid input! Try again" << std::endl;
	}
	return (input);
}

void Contact::addEntry() {
	first_name = getField("First name");
	last_name = getField("Last name");
	nickname = getField("Nickname");
	phone_number = getField("Phone number");
	darkest_secret = getField("Darkest secret");
	std::cout << "Entry Added!" << std::endl;
}

void Contact::printSearchResult() {
	std::cout 
		<< "First name: " << first_name << std::endl
		<< "Last name: " << last_name << std::endl
		<< "Nickname: " << nickname << std::endl
		<< "Phone number: " << phone_number << std::endl
		<< "Darkest secret: " << darkest_secret << std::endl;
}

void printField(const std::string &str) {
	if (str.length() > WIDTH)
		std::cout << "|" << std::setw(WIDTH) << std::right << str.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(WIDTH) << std::right << str;
}

void Contact::printRow(int index) {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(WIDTH) << index;
	printField(first_name);
	printField(last_name);
	printField(nickname);
	std::cout << "|" << std::endl;
}
