#include "Harl.hpp"
#include <iostream>
#include <string>

void	Harl::debug(){
	std::cout << "DEBUG\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::info() {
	std::cout << "INFO\n" << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning() {
	std::cout << "WARNING\n" << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void	Harl::error() {
	std::cout << "ERROR\n" << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level) {
	std::string tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*function[4])();

	function[0] = &Harl::debug;
	function[1] = &Harl::info;
	function[2] = &Harl::warning;
	function[3] = &Harl::error;

	for (int i = 0; i < 4; i++) {
		if (level == tab[i]) {
			(this->*function[i])();
			return;
		}
	}
}