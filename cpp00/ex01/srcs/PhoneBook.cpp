#include <iostream> //cout, cin, cerr, endl
#include <cstdlib> //exit, EXIT_FAILURE
#include <cctype> //isdigit
#include <sstream> //istringstream
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
: _entry_index(0), _entry_count(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::run() {
	std::string command;

	while (getlineWrapper(command)) {
		if (command == "ADD")
			add();
		else if (command == "SEARCH")
			search();
		else if (command == "EXIT")
			break;
		else
			printUsage();
		std::endl(std::cout);
	}
}

bool PhoneBook::getlineWrapper(std::string &command) {
	std::cout << "Enter a command:  ";
	if (!std::getline(std::cin, command))
		std::exit(EXIT_FAILURE);
	return true;
}

void PhoneBook::add() {
	_contacts[_entry_index % MAX_CONTACTS].addEntry();
	_entry_index++;
	if (_entry_count < MAX_CONTACTS)
		_entry_count++;
}

bool PhoneBook::strIsNumber(const std::string &str) {
	if (str.empty())
		return false;
	std::size_t i = 0;
	while (str[i])
		if (!std::isdigit(str[i++]))
			return false;
	return true;
}

int PhoneBook::strToInt(const std::string &str) {
	int ret;
	std::istringstream iss(str);
	iss >> ret;
	if (iss.fail())
		return -1;
	return ret;
}

int PhoneBook::getIndex() {
	std::string input;
	int index;
	std::cout << "Enter index to search for: ";
	if (!std::getline(std::cin, input))
		std::exit(EXIT_FAILURE);
	if (strIsNumber(input))
	{
		index = strToInt(input);
		if (index < _entry_count && index >= 0)
			return (index);
	}
	std::cout << "Not found!" << std::endl;
	return -1;
}

void PhoneBook::printTableHeader() {
	printField("index");
	printField("first");
	printField("last");
	printField("nickname");
	std::cout << "|" << std::endl;
}

void PhoneBook::printSearchTable() {
	std::cout << "---------------------------------------------" << std::endl;
	printTableHeader();
	int i = 0;
	while (i < _entry_count)
	{
		_contacts[i].printRow(i);
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::search() {
	int search_index;

	if (_entry_count == 0)
	{
		std::cerr << "No entries to search from yet!" << std::endl;
		return;
	}
	printSearchTable();
	search_index = getIndex();
	if (search_index == -1)
		return;
	_contacts[search_index].printSearchResult();
}

void PhoneBook::printUsage() {
	std::cerr << "\n-------------------USAGE------------------" << std::endl;
	std::cerr << " ADD\t:\tAdd a contact entry" << std::endl;
	std::cerr << " SEARCH\t:\tSearch for contact" << std::endl;
	std::cerr << " EXIT\t:\tExit program" << std::endl;
	std::cerr << "---------------------------------------------" << std::endl;
}
