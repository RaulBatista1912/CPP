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
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
	}
	catch (std::exception &e) {}
}

int	main() {
	srand(time(0));

	std::cout << "----test---" << std::endl;
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);

	std::cout << "\n----test2---" << std::endl;
	Base *ptr2 = generate();
	Base *ptr3 = generate();
	identify(*ptr2);
	identify(ptr2);
	identify(ptr3);
	identify(*ptr3);

	std::cout << "\n----testBadCastRef----" << std::endl;
	A *a = NULL;
	try {
		B &b = dynamic_cast<B&>(*a);
		(void)b;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----testBadCastPtr----" << std::endl;
	B *b = dynamic_cast<B*>(a);
	if (b == NULL)
		std::cout << "bad cast\n" << std::endl;

	std::cout << "\n----testMore----" << std::endl;
	B *b2 = NULL;
	A *a2 = dynamic_cast<A*>(b2);
	if (a2 == NULL)
		std::cout << "bad cast\n" << std::endl;

	std::cout << "\n----testMOREEEE----" << std::endl;
	A *a3 = NULL;
	identify(a3);

	std::cout << "\n----testMOREEEE2----" << std::endl;
	A a4;
	identify(a4);
	identify(a4);

	std::cout << "\n----testMOREEEE3----" << std::endl;
	C c;
	C c2 = dynamic_cast<C&>(c);

	std::cout << "\n----testMOREEEE4----" << std::endl;
	Base *c5 = NULL;
	A *a5 = dynamic_cast<A*>(c5);
	if (a5 == NULL)
		std::cout << "bad cast" << std::endl;

	delete ptr;
	delete ptr2;
	delete ptr3;

	//std::cout << "\n----testSegFault----" << std::endl;
	//C c3;
	//B &b9 = dynamic_cast<B&>(c3);
	//(void)b9;

	return (0);
}