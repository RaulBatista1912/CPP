#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "*Cat constructor called*" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "*Cat copy constructor called*" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "*Cat copy assignment operator called*" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat() {
	std::cout << "*Cat destructor called*" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Miaou!" << std::endl;
}