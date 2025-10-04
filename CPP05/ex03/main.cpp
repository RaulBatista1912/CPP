#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>
#include "Intern.hpp"

int	main()
{
	std::srand(std::time(0));

	std::cout << "-------Test ShrubberyCreationForm with 1 grade-------" << std::endl;
	Bureaucrat PDG("PDG", 1);
	ShrubberyCreationForm form_PDG("tree")
	;
	try {
		PDG.signForm(form_PDG);
		PDG.executeForm(form_PDG);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n-------Test ShrubberyCreationForm with 145 grade-------" << std::endl;
	Bureaucrat Noob("Noob", 145);
	ShrubberyCreationForm form_noob("test");
	try {
		Noob.signForm(form_noob);
		Noob.executeForm(form_noob);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n-------Test RobotomyRequestForm with 1 grade-------" << std::endl;
	Bureaucrat Robot("Robot", 1);
	RobotomyRequestForm form_robot("Braindead");
	try {
		Robot.signForm(form_robot);
		Robot.executeForm(form_robot);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n-------Test RobotomyRequestForm with 1 grade-------" << std::endl;
	Bureaucrat Robot2("Robot2", 1);
	RobotomyRequestForm form_robot2("Braindead");
	try {
		Robot2.signForm(form_robot2);
		Robot2.executeForm(form_robot2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n-------Test PresidentialPardonForm with 150 and 1 grade-------" << std::endl;
	Bureaucrat Normie("Normie", 150);
	Bureaucrat BOSS("BOSS", 1);
	PresidentialPardonForm Pardon("Jerome");
	try {
		Normie.executeForm(Pardon);
		Normie.signForm(Pardon);
		Normie.executeForm(Pardon);
		BOSS.signForm(Pardon);
		Normie.executeForm(Pardon);
		BOSS.executeForm(Pardon);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n-------Test PresidentialPardonForm with beSigned-------" << std::endl;
	Bureaucrat CEO("CEO", 1);
	PresidentialPardonForm PLS("please");
	try {
		CEO.executeForm(PLS);
		PLS.beSigned(CEO);
		std::cout << PLS;
		CEO.executeForm(PLS);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n-------Test Intern-------" << std::endl;
	Intern SomeRandomIntern;
	Bureaucrat BOSS2("BOSS2", 1);
	AForm* rrf = NULL;

	try {
		rrf = SomeRandomIntern.makeForm("robotomy request", "Bender");
		BOSS2.signForm(*rrf);
		BOSS2.executeForm(*rrf);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete rrf;

	std::cout << "\n-------Test Intern with wrong Form-------" << std::endl;
	Intern SomeRandomIntern2;
	Bureaucrat BOSS3("BOSS3", 1);
	AForm* rrf2 = NULL;

	try {
		rrf2 = SomeRandomIntern2.makeForm("not a Form", "Bender");
		BOSS3.signForm(*rrf2);
		BOSS3.executeForm(*rrf2);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	delete rrf2;
}