#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <string>


class AForm;

class Intern {
	public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(const std::string &name, const std::string &target);
		AForm	*createShrubbery(const std::string &target);
		AForm	*createRobotomy(const std::string &target);
		AForm	*createPresidential(const std::string &target);

		class InvalidArgument : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif