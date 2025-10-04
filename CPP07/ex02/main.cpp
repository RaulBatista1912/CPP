#include <iostream>
#include "Array.hpp"

int	main() {
	std::cout << "----test1----" << std::endl;
	Array<int> a(3);
	a[0] = '2';
	a[1] = '4';
	std::cout << "a[0] : " << a[0] - '0' << std::endl;
	Array<int> b = a;
	std::cout << "b[1] : " << b[1] - '0' << std::endl;
	Array<int> c(b);
	std::cout << "c[1] : " << c[1] - '0' << std::endl;
	std::cout << "c.size : " << c.size() << std::endl;

	std::cout << "\n----test2 out of bounds----" << std::endl;
	try
	{
		Array<std::string> test(1);
		test[4] = "lol";
		std::cout << test[4] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n----test3----" << std::endl;
	Array<std::string> str(3);
	try
	{
		std::cout << str[0] << std::endl;
		str[0] = "hello";
		str[1] = "world";
		str[2] = "!";
		std::cout << str[0] << " " << str[1] << str[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}