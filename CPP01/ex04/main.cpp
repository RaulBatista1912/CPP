#include <iostream>
#include <string>
#include <fstream>

int	replaceAndWrite(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Cannot open the input file" << std::endl;
		return (1);
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Cannot create the output file" << std::endl;
		inputFile.close();
		return (1);
	}
	std::string line;
	while (std::getline(inputFile, line)) {
		std::string result;
		size_t	start = 0;
		size_t	found = 0;
		while ((found = line.find(s1, start)) != std::string::npos) {
			result = result + line.substr(start, found - start);
			result = result + s2;
			start = found + s1.length();
		}
		result = result + line.substr(start);
		outputFile << result << '\n';
	}
	inputFile.close();
	outputFile.close();
	return (0);
}

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Error: ./main <filename> <s1> <s2> needed" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty()) {
		std::cerr << "Error: <s1> must not be empty" << std::endl;
		return (1);
	}
	if (replaceAndWrite(filename, s1, s2)) {
		return (1);
	}
	return (0);
}