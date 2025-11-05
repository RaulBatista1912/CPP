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
	float	numb = std::atof(value.c_str());

	if (is_good_date(date.substr(0, date.size() - 1)))
		std::cerr << "Error: bad date input => " << date << std::endl;
	else if (numb < 0 || numb > 1000 || is_good_value(value.substr(1, value.size()))) 
		std::cerr << "Error: bad value input =>" << value << std::endl;
	else {
		std::string key = date.substr(0, date.size() - 1);
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

int	is_good_date(std::string dateStr) {
	int	count = 0;
	std::istringstream iss(dateStr);
	std::string yearStr, monthStr, dayStr;

	std::getline(iss, yearStr, '-');
	std::getline(iss, monthStr, '-');
	std::getline(iss, dayStr, '-');

	int	month = std::atoi(monthStr.c_str());
	int	day = std::atoi(dayStr.c_str());
	int	year = std::atoi(yearStr.c_str());

	if (year < 2000 || year > 2999 || month < 1 || month > 12 || day < 1 || day > 31 || is_digit(yearStr) || is_digit(monthStr) || is_digit(dayStr))
		return 1;
	for (size_t i = 0; i < dateStr.size(); i++) {
		if (dateStr[i] == '-')
			count++;
	}
	if (count != 2)
		return 1;
	return 0;
}

int	is_good_value(std::string value) {
	int dot = 0;
	int	f = 0;

	for (size_t i = 0; i < value.size(); i++) {
		if (value[i] == '.')
			dot++;
		else if (value[i] == 'f')
			f++;
		else if (!std::isdigit(value[i]))
			return 1;
	}
	if (dot <= 1 && f <= 1)
		return 0;
	return 1;
}

int	is_digit(std::string numb) {
	for (size_t i = 0; i < numb.size(); i++) {
		if (!std::isdigit(numb[i]))
			return 1;
	}
	return 0;
}

void	trim_line(std::string line, std::string *date, std::string *value) {
	size_t sep = 0;
	for (size_t i = 0; i < line.size(); i++) {
		if (line[i] == '|')
			sep++;
	}
	if (sep != 1) {
		*value = "";
		*date = "";
		return;
	}
	sep = line.find('|');
	*date = line.substr(0, sep);
	*value = line.substr(sep + 1);
}

int	Check_arg(char *arg, std::map<std::string, double> data) {
	std::ifstream file(arg);
	if (!file.is_open()) {
		std::cerr << "Error: Cannot open the file" << std::endl;
		return 1;
	}
	std::string line;
	std::string date;
	std::string value;
	while (std::getline(file, line)) {
		trim_line(line, &date, &value);
		if (date.empty() || value.empty()) {
			std::cerr << "Error: bad input line => " << line << std::endl;
			continue;
		}
		if (date == "date " && value == " value")
			continue;
		Convert(date, value, data);
	}
	return 0;
}