#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: One argument needed!" << std::endl;
		return (1);
	}
	std::map<std::string, double> data;
	if (Stock_data_base(data))
		return (1);
	if (Check_arg(av[1], data))
		return (1);
	return (0);
}