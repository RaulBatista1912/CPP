#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static bool	isChar(const std::string &literal);
		static bool	isInt(const std::string &literal);
		static bool	isFloat(const std::string &literal);
		static bool	isDouble(const std::string &literal);

		static void	PrintChar(double value);
		static void PrintInt(double value);
		static void PrintFloat(double value);
		static void PrintDouble(double value);

		class WrongArgument : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	public:
		static void	convert(const std::string &literal);
};

#endif