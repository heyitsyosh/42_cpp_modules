#include <iostream> //cerr, endl
#include <fstream> //ifstream, ofstream, open, close, rdbuf
#include <sstream> //stringstream, rdbuf
#include "Main.hpp"

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr	<< "Usage:\t\t./mySed <file> <old-text> <new-text>\n"
					<< "Description:\t"
					<< "Replaces instances of 'old-text' with 'new-text' within the specified file.\n"
					<< "\t\tText is outputted to <file>.replace.\n"
					<< "Equivalent to:\t"
					<< "sed -i 's/old-text/new-text/g' <file>" << std::endl;
		return (1);
	}
	try {
		std::string filename = argv[1];
		if (filename.empty())
			throw std::string("Invalid file!");
		std::string oldText = argv[2];
		if (oldText.empty())
			throw std::string("Invalid old-text!");
		std::string newText = argv[3];
		replace(filename, oldText, newText);
	}
	catch (const std::string &e) {
		std::cerr << e << std::endl;
		return (1);
	}
}

void replace(std::string &filename, std::string &oldText, std::string &newText) {
	std::string buf = read_file(filename);
	edit_buf(buf, oldText, newText);
	write_file(filename, buf);
}

std::string read_file(std::string &filename) {
	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open())
		throw std::string("Unable to open ") + filename;
	std::stringstream buf;
	buf << ifs.rdbuf();
	if (ifs.fail()) 
		throw std::string("Error reading from ") + filename;
	ifs.close();
	return buf.str();
}

void edit_buf(std::string &buf, std::string &oldText, std::string &newText) {
	size_t pos = 0;
	while ((pos = buf.find(oldText, pos)) != std::string::npos)
	{
		buf.erase(pos, oldText.length());
		buf.insert(pos, newText);
		pos += newText.length();
	}
}

void write_file(std::string &filename, std::string &buf) {
	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
		throw std::string("Unable to open ") + filename + ".replace";
	ofs << buf;
	ofs.close();
}
