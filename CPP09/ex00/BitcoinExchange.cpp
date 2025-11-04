#include "BitcoinExchange.hpp"

int	Stock_data_base(std::map<std::string, double>& data) {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: Cannot open the 'data.csv'" << std::endl;
		return (1);
	}
	std::string date;
	std::string valuestr;
	while (std::getline(file, date, ',') && std::getline(file, valuestr)) {
		if (date == "date" && valuestr == "exchange_rate")
			continue;
		double value = std::strtod(valuestr.c_str(), 0);
		data[date] = value;
	}
	file.close();
	return (0);
}

void	Convert(std::string date, std::string value, std::map<std::string, double> data) {
	std::string yearStr, monthStr, dayStr;
	std::istringstream iss(date);

	std::getline(iss, yearStr, '-');
	std::getline(iss, monthStr, '-');
	std::getline(iss, dayStr, '-');

	int	month = std::atoi(monthStr.c_str());
	int	day = std::atoi(dayStr.c_str());
	float	numb = std::atof(value.c_str());
	if (date.length() != 11 || month < 1 || month > 12 || day < 1 || day > 31)
		std::cerr << "Error: bad date input => " << date << std::endl;
	else if (numb < 0 || numb > 1000)
		std::cerr << "Error: bad value input =>" << value << std::endl;
	else {
		std::string key = date.substr(0, 10);
		std::map<std::string, double>::const_iterator it = data.lower_bound(key);
		if (it == data.end())
			--it;
		else if (it->first != key) {
			if (it == data.begin()) {
				std::cerr << "Error: no available date before => " << key << std::endl;
				return;
			}
			--it;
		}
		double rate = it->second;
		std::cout << key << " => " << value << " = " << numb * rate << std::endl;
	}
}

int	Check_arg(char *arg, std::map<std::string, double> data) {
	std::ifstream file(arg);
	if (!file.is_open()) {
		std::cerr << "Error: Cannot open the file" << std::endl;
		return 1;
	}
	std::string date;
	std::string value;
	while (std::getline(file, date, '|') && std::getline(file, value)) {
		if (date == "date " && value == " value")
			continue;
		Convert(date, value, data);
	}
	return 0;
}