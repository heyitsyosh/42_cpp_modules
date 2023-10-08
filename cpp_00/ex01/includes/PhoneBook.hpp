#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void run();

private:
	Contact	contacts[MAX_CONTACTS];
	int	entry_index;
	int	entry_count;

	bool getlineWrapper(std::string& command);
	void add();
	void search();
	void printUsage();
	bool strIsNumber(const std::string& str);
	int strToInt(const std::string& str);
	int	getIndex();
	void printSearchTable();
	void printTableHeader();
};

#endif
