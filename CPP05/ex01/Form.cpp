#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), sign_grade(100), execute_grade(50) {

}

Form::Form(const std::string &name, int sign_grade, int execute_grade) : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade) {
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade) {

}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

Form::~Form() {

}

std::string	Form::getName() const {
	return name;
}

bool	Form::getIsSigned() const {
	return is_signed;
}

int	Form::getSignGrade() const {
	return sign_grade;
}

int	Form::getExecuteGrade() const {
	return execute_grade;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade)
		throw GradeTooLowException();
	is_signed = true;
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form: Grade is too low!";
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form: Grade is too high!";
}

std::ostream &operator<<(std::ostream &os, const Form &other) {
	os << "Form : " << other.getName() << ", signed: " << (other.getIsSigned() ? "yes" : "no") << ", sign grade: " << other.getSignGrade() << ", execute grade: " << other.getExecuteGrade() << std::endl;
	return os;
}