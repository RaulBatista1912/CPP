#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <sstream>

int	main() {
	PhoneBook pb;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			break;
		}
		if (command == "ADD") {
			pb.addContact();
		}
		else if (command == "SEARCH") {
			pb.displayContacts();
			while (true) {
				std::cout << "Enter index to view: ";
				std::string indexStr;
				std::getline(std::cin, indexStr);
				if (std::cin.eof()) {
					std::cout << "Exiting...\n";
					return 0;
				}
				std::stringstream ss(indexStr);
				int	index;
				if (!(ss >> index) || !ss.eof()) {
					std::cout << "Invalid input. Must be a valid number.\n";
					pb.displayContacts();
					continue;
				}
				if (pb.showContactDetails(index))
					break;
				else
					pb.displayContacts();
			}
		}
		else if (command == "EXIT") {
			std::cout << "Goodbye!\n";
			break;
		}
		else {
			std::cout << "Unknown command.\n";
		}
	}
	return (0);
}