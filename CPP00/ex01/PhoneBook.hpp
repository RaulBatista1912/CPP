#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts[8];
	int	TotalContacts;
	int	NextIndex;

	std::string formatField(std::string field) const;

public:
	PhoneBook();
	void	addContact();
	void	displayContacts() const;
	bool	showContactDetails(int index) const;
};

#endif