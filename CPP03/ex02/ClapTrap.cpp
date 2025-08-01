#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called! HP: " << hitPoints << " , EP: " << energyPoints << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructed! HP: " << hitPoints << " , EP: " << energyPoints << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << name << " copied!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << name << " assigned!\n";
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destroyed!\n";
}

void	ClapTrap::attack(const std::string& target) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't attack, not enough energyPoints or hitPoints! HP: " << hitPoints << " , EP: " << energyPoints << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage! HP: " <<hitPoints << " , EP: " << energyPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! HP: " << hitPoints << " , EP: " << energyPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints <= 0 || energyPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't repair itself, not enough energyPoints or hitPoints! HP: " << hitPoints << " , EP: " << energyPoints << std::endl;
		return ;
	}
	--energyPoints;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs itselfs for " << amount << " hitPoints! HP: " << hitPoints << " , EP: " << energyPoints << std::endl;
}