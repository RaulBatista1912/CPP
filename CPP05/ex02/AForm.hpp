#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			execute_grade;

	public:
		AForm();
		AForm(const std::string &name, int sign_grade,int execute_grade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		virtual void	execute(Bureaucrat const &executor) const = 0;

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

		class FormNotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class CannotOpenFile : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif