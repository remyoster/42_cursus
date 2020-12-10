#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string str)
	: Form ("ShrubberyCreationForm", 145, 137) {
	this->setTarget(str);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs) {
		this->setIsSigned(rhs.getIsSigned());
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

void	ShrubberyCreationForm::action() const {
	std::ofstream myFile;
	std::string filename(this->getTarget() + "_shrubbery");
	myFile.open (filename.c_str());
	const char *tree =
	"      .     .  .      +     .      .          .\n"
    " .       .      .     #       .           .\n"
    "    .      .         ###            .      .      .\n"
    "  .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
    "      .      . \"####\"###\"####\"  .\n"
   "    .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
  ".             \"#########\"#########\"        .        .\n"
  "      .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
  "  .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
 "               .\"##\"#####\"#####\"##\"           .      .\n"
  "  .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
 "    .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
"  .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
  "          .     \"    000      \"    .     .\n"
 "     .         .   . 000     .        .       .\n"
"....................O000O.................................";
	myFile << tree << "\n\n" << tree << "\n\n"; 
	myFile.close();
}
