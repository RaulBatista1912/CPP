#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "*Dog constructor called*" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::~Dog() {
	std::cout << "*Dog destructor called*" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "*Dog copy constructor called*" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "*Dog copy assignment operator called*" << std::endl;
	if (this != &other) {
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}