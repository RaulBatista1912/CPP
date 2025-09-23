#include <ctime>
#include <stdlib.h>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int	r = std::rand() % 3;
	if (r == 0)
		return new A;
	else if (r == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void	identify(Base &p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch (std::exception &e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B\n";
	}
	catch (std::exception &e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C\n";
	}
	catch (std::exception &e) {}
}

int	main() {
	srand(time(0));
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}