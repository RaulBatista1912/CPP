#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int	main()
{
	std::srand(std::time(0));

	std::cout << "-------Test ShrubberyCreationForm with 1 grade-------" << std::endl;
	Bureaucrat PDG("PDG", 1);
	ShrubberyCreationForm form_PDG("tree");
	try {
		PDG.signForm(form_PDG);
		PDG.executeForm(form_PDG);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------Test ShrubberyCreationForm with 145 grade-------" << std::endl;
	Bureaucrat Noob("Noob", 145);
	ShrubberyCreationForm form_noob("test");
	try {
		Noob.signForm(form_noob);
		Noob.executeForm(form_noob);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------Test RobotomyRequestForm with 1 grade-------" << std::endl;
	Bureaucrat Robot("Robot", 1);
	RobotomyRequestForm form_robot("Braindead");
	try {
		Robot.signForm(form_robot);
		Robot.executeForm(form_robot);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------Test RobotomyRequestForm with 1 grade-------" << std::endl;
	Bureaucrat Robot2("Robot2", 1);
	RobotomyRequestForm form_robot2("Braindead");
	try {
		Robot2.signForm(form_robot2);
		Robot2.executeForm(form_robot2);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
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
		std::cout << e.what() << std::endl;
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
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------Test-------" << std::endl;
	AForm *a = new PresidentialPardonForm("pardon");

	a->beSigned(CEO);
	a->execute(CEO);
	delete a;

	std::cout << "\n-------Test2-------" << std::endl;
	AForm *b = new RobotomyRequestForm("robot");
	(*b).beSigned(CEO);
	CEO.executeForm(*b);
	delete b;

	std::cout << "\n-------Testggg-------" << std::endl;
	PresidentialPardonForm fds;
	fds = PLS;
	CEO.executeForm(fds);
}