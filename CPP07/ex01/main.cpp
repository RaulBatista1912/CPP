#include <iostream>
#include <ctype.h>
#include "iter.hpp"

void	incr(int &i) {
	i++;
}

void	print(const int &i) {
	std::cout << i;
}

void	my_toupper(std::string &str) {
	for(size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
}

int	main() {
	int	tab[] = {1, 2, 3, 4};
	for(int i = 0; i < 4; i++) {
		std::cout << tab[i];
	}
	std::cout << "\n";
	iter(tab, 4, incr);
	for(int i = 0; i < 4; i++) {
		std::cout << tab[i];
	}
	std::cout << "\n" << std::endl;

	int	tab2[] = {1, 2, 3, 4};
	iter(tab2, 4, print);
	std::cout << "\n" << std::endl;

	std::string str[] = {"hello", "bye", "asgard"};
	iter(str, 3, my_toupper);
	for(int i = 0; i < 3; i++) {
		std::cout << str[i] << std::endl;
	}
}