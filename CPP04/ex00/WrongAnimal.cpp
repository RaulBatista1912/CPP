#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "*WrongAnimal constructor called*" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)  : type(other.type) {
	std::cout << "*WrongAnimal copy constructor called*" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "*WrongAnimal copy assignement operator called*" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "*Wrong Animal destructor called*" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a strange sound" << std::endl;
}