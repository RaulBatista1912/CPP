#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"


Intern::Intern() {

}

Intern::Intern(Intern const &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {

}

const char* Intern::InvalidArgument::what() const throw() {
	return "Intern: Invalid Form!";
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << formNames[i] << std::endl;
			switch (i) {
			case 0: return new ShrubberyCreationForm(target);
			case 1: return new RobotomyRequestForm(target);
			case 2: return new PresidentialPardonForm(target);
			}
		}
	}
	throw InvalidArgument();
}