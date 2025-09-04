#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned())
		throw RobotomyRequestForm::FormNotSigned();
	if (executor.getGrade() > getExecuteGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	std::cout << "BRRRrrrrrrr" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << target << " Robotomy failed on " << target << "!" << std::endl;
}