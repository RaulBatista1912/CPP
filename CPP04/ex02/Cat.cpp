#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "*Cat constructor called*" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::~Cat() {
	std::cout << "*Cat destructor called*" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "*Cat copy constructor called*" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "*Cat copy assignment operator called*" << std::endl;
	if (this != &other) {
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Miaou!" << std::endl;
}