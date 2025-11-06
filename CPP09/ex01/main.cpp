#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: One argument needed!" << std::endl;
		return (1);
	}
	std::string line;
	if(check_arg(av[1], &line))
		return (1);
	Convert(line);
	return (0);
}