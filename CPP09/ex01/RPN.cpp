#include "RPN.hpp"

int	check_arg(char *av, std::string *line) {
	int	op_count = 0;
	int	numb_count = 0;

	for (size_t i = 0; i < strlen(av); i++) {
		if (av[i] != ' ')
			*line += av[i];
		if (av[i] != ' ' && !isdigit(av[i]) && av[i] != '+' && av[i] != '-' && av[i] != '/' && av[i] != '*') {
			std::cerr << "Error: bad input => '" << av << "'" <<  std::endl;
			return (1);
		}
		if (isdigit(av[i]))
			numb_count++;
		else if (av[i] == '+' || av[i] == '-' || av[i] == '/' || av[i] == '*')
			op_count++;
	}
	if (numb_count - 1 != op_count) {
		std::cerr << "Error: bad input => '" << av << "'" << std::endl;
		return (1);
	}
	return (0);
}

void	Convert(std::string line) {
	std::stack<int> stack;
	for (size_t i = 0; i < line.size(); i++) {
		if (std::isdigit(line[i]))
			stack.push(line[i] - '0');
		else {
			if (stack.size() < 2) {
				std::cerr << "Error: not enough elements in the stack to perform operation => '" << line << "'" << std::endl;
				return;
			}
			int	a = stack.top();
			stack.pop();
			int	b = stack.top();
			stack.pop();
			int	result = 0;
			switch (line[i]) {
				case '+': result = b + a; break;
				case '-': result = b - a; break;
				case '*': result = b * a; break;
				case '/':
					if (a == 0) {
						std::cerr << "Error: impossible to divide by zero!" << std::endl;
						return;
					}
					result = b / a;
					break;
			}
			stack.push(result);
		}
	}
	std::cout << stack.top() << std::endl;
}