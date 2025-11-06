#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: One argument needed!" << std::endl;
		return (1);
	}
	std::stack<int> stack;
	if(check_arg(av[1], stack))
		return (1);
}