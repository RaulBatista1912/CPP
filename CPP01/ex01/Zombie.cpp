#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << name << " is destroyed." << std::endl;
}

void	Zombie::setName(const std::string& name) {
	this->name = name;
}

void	Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}