#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>

int			main(int argc, char **argv);
void		replace(std::string &file, std::string &oldText, std::string &newText);
void		edit_buf(std::string &buf, std::string &oldText, std::string &newText);
std::string	read_file(std::string &file);
void		write_file(std::string &file, std::string &buf);

#endif
