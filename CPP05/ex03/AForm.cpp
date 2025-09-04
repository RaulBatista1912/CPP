#include "AForm.hpp"

AForm::AForm() : name("Default"), is_signed(false), sign_grade(100), execute_grade(50) {

}

AForm::AForm(const std::string &name, int sign_grade, int execute_grade) : name(name), is_signed(false), sign_grade(sign_grade), execute_grade(execute_grade) {
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade) {

}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

AForm::~AForm() {

}

std::string	AForm::getName() const {
	return name;
}

bool	AForm::getIsSigned() const {
	return is_signed;
}

int	AForm::getSignGrade() const {
	return sign_grade;
}

int	AForm::getExecuteGrade() const {
	return execute_grade;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade)
		throw GradeTooLowException();
	is_signed = true;
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Form: Grade is too low!";
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Form: Grade is too high!";
}

const char* AForm::FormNotSigned::what() const throw() {
	return "Form not signed!";
}

const char* AForm::CannotOpenFile::what() const throw() {
	return "Cannot open file!";
}

std::ostream &operator<<(std::ostream &os, const AForm &other) {
	os << "Form : " << other.getName() << ", signed: " << (other.getIsSigned() ? "yes" : "no") << ", sign grade: " << other.getSignGrade() << ", execute grade: " << other.getExecuteGrade() << std::endl;
	return os;
}