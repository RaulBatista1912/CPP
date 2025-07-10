#ifndef CLAPPTRAP_HPP
#define CLAPPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap {
	protected:
		std::string	name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		ClapTrap(const std::string& name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif