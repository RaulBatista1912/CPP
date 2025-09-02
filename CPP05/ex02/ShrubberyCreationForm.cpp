#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShruberryCreationForm", 145, 137), target("Default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw ShrubberyCreationForm::FormNotSigned();
	if (executor.getGrade() > getExecuteGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
		throw ShrubberyCreationForm::CannotOpenFile();
	file << "          &&& &&  & &&\n";
	file << "      && &&& ()|/ @, &&\n";
	file << "     &(/&/&||/& /_/)_&/_&\n";
	file << "    &() &&&|()|/& _ '% & ()\n";
	file << "  &_&&_ |& |&&/&__&&%_/_& &&\n";
	file << "&&   && & &| &| /& & % ()& /&&\n";
	file << "  ()&_---()&&&-&&--%---()~\n";
	file << "     &&      |||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "       , -=-~  .-^- _\n";

	file.close();
	std::cout << "Shrubbery created: " << target + "_shrubbery" << std::endl;
}