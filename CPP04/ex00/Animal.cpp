#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "*Animal constructor called*" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "*Animal copy constructor called*" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "*Animal copy assignement operator called*" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "*Animal destrctor called*" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {
	std::cout << "Animal makes a generic sound" << std::endl;
}
