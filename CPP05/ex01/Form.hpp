#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			execute_grade;

	public:
		Form();
		Form(const std::string &name, int sign_grade,int execute_grade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		void		beSigned(const Bureaucrat &bureaucrat);
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif