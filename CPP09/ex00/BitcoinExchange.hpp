#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <string>
#include <ctype.h>

int	Stock_data_base(std::map<std::string, double>& data);
int	Check_arg(char *arg, std::map<std::string, double> data);
void	Convert(std::string date, std::string value, std::map<std::string, double> data);
int	is_digit(std::string numb);
int	is_good_value(std::string value);
int	is_good_date(std::string dateStr);
void	trim_line(std::string line, std::string *date, std::string *value);