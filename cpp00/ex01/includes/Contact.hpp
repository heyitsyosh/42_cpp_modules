#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

#define MAX_CONTACTS 8

class Contact {
public:
	Contact();
	~Contact();
	void addEntry();
	void printRow(int index);
	void printSearchResult();
private:
//	Data members
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
//	Functions
	std::string getField(const std::string &field_type);
};

void printField(const std::string &str);

#endif
