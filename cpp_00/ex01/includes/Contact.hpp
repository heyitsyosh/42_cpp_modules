#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

# define MAX_CONTACTS 8

class Contact {
public:
	Contact();
	~Contact();

	void addEntry();
	void printRow(int index);
	void printSearchResult();

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::string getField(const std::string& field_type);
};

void	printField(const std::string& str);

#endif
