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
}