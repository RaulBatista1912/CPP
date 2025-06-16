#include "Contact.hpp"

Contact::Contact() {}

void Contact::setContact(std::string fn, std::string ln, std::string nn,
							std::string pn, std::string ds) {
	FirstName = fn;
	LastName = ln;
	Nickname = nn;
	PhoneNumber = pn;
	DarkestSecret = ds;
}

std::string Contact::getFirstName() const {
	return FirstName;
}

std::string Contact::getLastName() const {
	return LastName;
}

std::string Contact::getNickname() const {
	return Nickname;
}

std::string Contact::getPhoneNumber() const {
	return PhoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return DarkestSecret;
}
