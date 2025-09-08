#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

const char *ScalarConverter::WrongArgument::what() const throw() {
	return "Error: Conversion impossible";
}

bool	ScalarConverter::isChar(const std::string &literal) {
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string &literal) {
	size_t	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.size()) {
		if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &literal) {
	bool	dot = false;
	size_t	i = 0;
	bool	f = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	while (i < literal.size()) {
		if (literal[i] == '.') {
			if (dot == true)
				return (false);
			dot = true;
		}
		else if (literal[i] == 'f' || literal[i] == 'F') {
			if (f == true)
				return (false);
			f = true;
		}
		i++;
	}
	if (f == true && (literal[i - 1] == 'f' || literal[i - 1] == 'F'))
		return (true);
	return (false);
}

bool	ScalarConverter::isDouble(const std::string &literal) {
	bool	dot = false;
	size_t	i = 0;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	while (i < literal.size()) {
		if (literal[i] == '.') {
			if (dot == true)
				return false;
			else if (dot == false)
				dot = true;
		}
		i++;
	}
	return (dot);
}

void	ScalarConverter::PrintChar(double value) {
	if (value != value || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void	ScalarConverter::PrintInt(double value) {
	if (value != value || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::PrintFloat(double value) {
	if (value != value)
		std::cout << "float: nanf" << std::endl;
	else if (value == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (value == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
}

void	ScalarConverter::PrintDouble(double value) {
	if (value != value)
		std::cout << "double: nan" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void	ScalarConverter::convert(const std::string &literal) {
	double	value = 0.0;
	char	*end;

	try {
		if (literal == "+inff" || literal == "+inf")
			value = std::numeric_limits<double>::infinity();
		else if (literal == "-inff" || literal == "-inf")
			value = -std::numeric_limits<double>::infinity();
		else if (literal == "nan" || literal == "nanf")
			value = NAN;
		else if (isChar(literal))
			value = static_cast<double>(literal[0]);
		else if (isInt(literal))
			value = std::strtod(literal.c_str(), &end);
		else if (isFloat(literal))
			value = std::strtod(literal.c_str(), &end);
		else if (isDouble(literal))
			value = std::strtod(literal.c_str(), &end);
		else
			throw WrongArgument();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return;
	}
	PrintChar(value);
	PrintInt(value);
	PrintFloat(value);
	PrintDouble(value);
	return;
}