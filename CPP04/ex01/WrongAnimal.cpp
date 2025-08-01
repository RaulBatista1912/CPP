#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "*Wrong Animal constructor called*" << std::endl;
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