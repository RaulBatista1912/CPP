#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <string>

int	Stock_data_base(std::map<std::string, double>& data);
int	Check_arg(char *arg, std::map<std::string, double> data);
void	Convert(std::string date, std::string value, std::map<std::string, double> data);