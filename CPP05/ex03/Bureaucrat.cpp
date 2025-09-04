#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {

}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {

}

const std::string&	Bureaucrat::getName() const {
	return name;
}

int	Bureaucrat::getGrade() const {
	return grade;
}

void	Bureaucrat::incrementGrade() {
	if (grade <= 1) {
		throw GradeTooHighException();
	}
	grade--;
}

void	Bureaucrat::decrementGrade() {
	if (grade >= 150) {
		throw GradeTooLowException();
	}
	grade++;
}

void	Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout<< this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e){
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";
	return os;
}