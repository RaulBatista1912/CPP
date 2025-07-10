#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	ClapTrap a("Bob");
	a.attack("Fanta");
	std::cout << "\n";

	ScavTrap b("Aymeric");
	b.attack("Poo");
	std::cout << "\n";

	FragTrap c("Caillou");
	c.attack("Pierre");
	c.attack("poo");
	FragTrap g = c;
	g.attack("Tree");
	std::cout << "\n";

	ClapTrap d("Bully");
	d.takeDamage(100);
	std::cout << "\n";

	c.highFivesGuys();
	b.guardGate();
	std::cout << "\n";
}