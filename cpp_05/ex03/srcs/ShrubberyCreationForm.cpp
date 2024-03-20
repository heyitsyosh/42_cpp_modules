#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> //ofstream

ShrubberyCreationForm::ShrubberyCreationForm()
:	AForm("ShrubberyCreationForm", grade_to_sign, grade_to_exec), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
:	AForm("ShrubberyCreationForm", grade_to_sign, grade_to_exec), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeInDerived() const {
	std::string filename = getName() + "_shrubbery";
	std::ofstream file;
	file.open(filename.c_str());
	if (!file.is_open())
        throw std::runtime_error("Failed to open file: " + filename);
	file <<
"                                                         .\n"
"                                              .         :  \n"
"                 .              .              :%     ::   \n"
"                   ,           ,                ::%  %:   \n"
"                    :         :                   ::%:'     .,   \n"
"           ,.        %:     %:            :        %:'    ,:\n"
"             \\:       \\:%:  %%:        ,     %:    :%:    ,%'\n"
"              %:       %:%:      ,  :       %:  :%:   ,%:' \n"
"               :%:      %:        :%:        % :%:  ,%:'\n"
"                `%:.     :%:     %:'         `:%%:.%:'\n"
"                 `::%.    :%%. %@:        %: :@%:%'\n"
"                    `:%:.  ::bd%:          %:@%:'\n"
"                      `@%:.  ::%.         :@@%:'   \n"
"                        `@%.  `:@%.      :@@%:         \n"
"                          `@%%. `@%%    :@@%:        \n"
"                            :@%. :@%%  %@@%:       \n"
"                              %@bd%%%bd%%::     \n"
"                                #@%%%%%:::\n"
"                                %@@%%%:::\n"
"                                %@@@%(o):  . '         \n"
"                                %@@@o%::(.,'         \n"
"                            `.. %@@@o%:::         \n"
"                               `)@@@o%:::         \n"
"                                %@@(o):::        \n"
"                               .%@@@@%:::         \n"
"                               :%@@@@%:::.          \n"
"                              :%@@@@%%::::. \n"
"                          ...:%@@@@@%%:::::,.. " << std::endl;
}
