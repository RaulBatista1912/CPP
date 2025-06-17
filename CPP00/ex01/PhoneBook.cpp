#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdio>

PhoneBook::PhoneBook() : TotalContacts(0), NextIndex(0) {}

std::string PhoneBook::formatField(std::string field) const {
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return std::string(10 - field.length(), ' ') + field;
}

void	PhoneBook::addContact() {
	std::string fn, ln, nn, pn, ds;

	std::cout << "First Name: ";
	if (!std::getline(std::cin, fn)) {
		if (std::cin.eof()) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << "\nInput canceled. Contact not saved. Returning to main menu\n";
			return;
		}
	}
	std::cout << "Last Name: ";
	if (!std::getline(std::cin, ln)) {
		if (std::cin.eof()) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << "\nInput canceled. Contact not saved. Returning to main menu\n";
			return;
		}
	}
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, nn)) {
		if (std::cin.eof()) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << "\nInput canceled. Contact not saved. Returning to main menu\n";
			return;
		}
	}
	std::cout << "Phone Number: ";
	if (!std::getline(std::cin, pn)) {
		if (std::cin.eof()) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << "\nInput canceled. Contact not saved. Returning to main menu\n";
			return;
		}
	}
	std::cout << "Darkest Secret: ";
	if (!std::getline(std::cin, ds)) {
		if (std::cin.eof()) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << "\nInput canceled. Contact not saved. Returning to main menu\n";
			return;
		}
	}

	if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty()){
		std::cout << "All fields must be filled. Contact not saved.\n";
		return;
	}

	contacts[NextIndex].setContact(fn, ln, nn, pn, ds);
	NextIndex = (NextIndex + 1) % 8;
	if (TotalContacts < 8)
		TotalContacts++;
	std::cout << "Contact added.\n";
}

void	PhoneBook::displayContacts() const {
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "\n";

	for (int i = 0; i < TotalContacts; ++i) {
		std::cout	<< std::setw(10) << i << "|"
					<< formatField(contacts[i].getFirstName()) << "|"
					<< formatField(contacts[i].getLastName()) << "|"
					<< formatField(contacts[i].getNickname()) << "\n";
	}
}

bool	PhoneBook::showContactDetails(int index) const {
	if (index < 0 || index >= TotalContacts) {
		std::cout << "Invalid index.\n";
		return false;
	}

	std::cout << "First Name: " << contacts[index].getFirstName() << "\n";
	std::cout << "Last Name: " << contacts[index].getLastName() << "\n";
	std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
	return true;
}