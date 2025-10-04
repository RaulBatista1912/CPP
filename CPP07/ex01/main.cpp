#include <iostream>
#include <ctype.h>
#include "iter.hpp"

void	incr(int &i) {
	i++;
}

template <typename T>
void	print(const T& value) {
	std::cout << value;
}

void	my_toupper(std::string &str) {
	for(size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
}

int	main() {
	std::cout << "----test1----" << std::endl;
	int	tab[] = {1, 2, 3, 4};
	for(int i = 0; i < 4; i++) {
		std::cout << tab[i] << " ";
	}
	std::cout << "\n";
	iter(tab, 4, incr);
	for(int i = 0; i < 4; i++) {
		std::cout << tab[i] << " ";
	}
	std::cout << "\n" << std::endl;

	std::cout << "----test2----" << std::endl;
	int	tab2[] = {1, 2, 3, 4};
	iter(tab2, 4, print<int>);
	std::cout << "\n" << std::endl;

	std::cout << "----test3----" << std::endl;
	std::string str[] = {"hello\n", "bye\n", "asgard\n"};
	iter(str, 3, my_toupper);
	iter(str, 3, print<std::string>);
}