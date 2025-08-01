#include "Brain.hpp"

Brain::Brain() {
	std::cout << "*Brain construcor called*" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "*Brain copied*" << std::endl;
	for (int i = 0; i < 100; i++)
		this->idea[i] = other.idea[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "*Brain assigned*" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->idea[i] = other.idea[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "*Brain destructor called*" << std::endl;
}