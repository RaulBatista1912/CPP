#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
			std::string FirstName;
			std::string LastName;
			std::string Nickname;
			std::string PhoneNumber;
			std::string DarkestSecret;

	public:
			Contact();
			bool isEmpty() const;
			void setContact(std::string FirstName, std::string LastName, std::string Nickname,
							std::string PhoneNumber, std::string DarkestSecret);
			std::string getFirstName() const;
			std::string getLastName() const;
			std::string getNickname() const;
			std::string getPhoneNumber() const;
			std::string getDarkestSecret() const;
};

#endif