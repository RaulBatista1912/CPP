#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		for(size_t j = 0; j < arg.length(); j++)
			std::cout << (char)toupper(arg[j]);
		if (i < ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}