#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "-------Test with Bob, 151 grade-------" << std::endl;
	try {
		Bureaucrat Bob("Bob", 151);
		std::cout << Bob;
	}
	catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------Test with Pierre, 3 grade-------" << std::endl;
	try {
		Bureaucrat Pierre("Pierre", 3);
		std::cout << Pierre;
	}
	catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------Test with Jean, -9000 grade-------" << std::endl;
	try {
		Bureaucrat Jean("Jean", -9000);
		std::cout << Jean;
	}
	catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------test increasing-------" << std::endl;
	Bureaucrat Luc("Luc", 50);
	std::cout << Luc;
	try {
		Luc.incrementGrade();
	}
	catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << Luc;

	std::cout << "\n-------test increasing-------" << std::endl;
	Bureaucrat Dechavanne("Dechavanne", 1);
	std::cout << Dechavanne;
	try {
		Dechavanne.incrementGrade();
	}
	catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << Dechavanne;

	std::cout << "\n-------test Form-------" << std::endl;
	Form important_Form("important_Form", 50, 50);
	Bureaucrat PDG("PDG", 1);
	std::cout << PDG;
	std::cout << important_Form;
	PDG.signForm(important_Form);
	std::cout << important_Form;

	std::cout << "\n-------test Form-------" << std::endl;
	Form not_For_Normies("not_For_Normies", 149, 149);
	Bureaucrat Normie("Normie", 150);
	std::cout << Normie;
	std::cout << not_For_Normies;
	Normie.signForm(not_For_Normies);
	std::cout << not_For_Normies;
	Normie.incrementGrade();
	std::cout << Normie;
	Normie.signForm(not_For_Normies);
	std::cout << not_For_Normies;

	std::cout << "\n-------test Form-------" << std::endl;
	try {
		Form Wrong_Form("Wrong_Form", 300, -9000);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------test Form-------" << std::endl;
	Form test_Form("test_Form", 100, 50);
	Bureaucrat Random("Random", 101);
	try {
		Random.signForm(test_Form);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}