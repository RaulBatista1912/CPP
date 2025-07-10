#include "ClapTrap.hpp"

int main() {
	ClapTrap ct("Bob");
	ct.attack("Pierre");
	ct.takeDamage(4);
	ct.beRepaired(3);
	ct.takeDamage(10);
	ct.attack("another tree");
	ct.beRepaired(5);
	std::cout << "\n";

	ClapTrap b = ct;
	b.beRepaired(5);
	std::cout << "\n";
	
	ClapTrap a;
	a.attack("Poo");
	a.attack("Poo");
	a.attack("Poo");
	a.attack("Poo");
	a.attack("Poo");
	a.attack("Poo");
	a.attack("Poo");
	a.attack("Poo");
	a.attack("Poo");
	a.attack("Poo");
	a.takeDamage(5);
	a.beRepaired(4);
	a.takeDamage(10000000);
	a.attack("Jean");
	a.beRepaired(9000);
	std::cout << "\n";
	return 0;
}
