#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int	main() {
	std::srand(time(0));

	std::cout << "---test exception and longest/shortest----" << std::endl;
	Span sp(4);
	sp.addNumber(1);
	sp.addNumber(35);
	sp.addNumber(12);
	sp.addNumber(9);
	try {
		sp.addNumber(3);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "longest span : " << sp.longestSpan() << std::endl;

	std::cout << "\n---test 4 random numbers----" << std::endl;
	Span mid(4);
	std::vector<int> v;
	for (int i = 0; i < 4; i++) {
		int	random = rand() % 4;
		v.push_back(random);
	}
	try {
		mid.addMultipleNumbers(v.begin(), v.end());
		std::cout << "shortest span : " << mid.shortestSpan() << std::endl;
		std::cout << "longest span : " << mid.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	for (int j = 0; j < 4; j++) {
		std::cout << v[j] << std::endl;
	}

	std::cout << "\n---test not enough numbers----" << std::endl;
	Span small(1);
	try {
		small.addNumber(1);
		std::cout << "shortest span : " << small.shortestSpan() << std::endl;
		std::cout << "longest span : " << small.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---test big span----" << std::endl;
	Span big(100000);
	std::vector<int> v2;
	for (int i = 0; i < 100000; i++) {
		int	big_numb = rand() % 100000;
		v2.push_back(big_numb);
	}
	try {
		big.addMultipleNumbers(v2.begin(), v2.end());
		std::cout << "shortest span : " << big.shortestSpan() << std::endl;
		std::cout << "longest span : " << big.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
}