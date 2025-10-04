#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	vec.push_back(12);
	vec.push_back(9);
	vec.push_back(42);
	vec.push_back(76);
	
	std::cout << "----test1----" << std::endl;
	std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 42);
	if (it != vec.end())
		std::cout << *it << " found\n";
	else
		std::cout << "number not found\n";

	std::cout << "\n----test2----" << std::endl;
	std::vector<int>::iterator it2 = std::find(vec.begin(), vec.end(), 2);
	if (it2 != vec.end())
		std::cout << *it2 << " found\n";
	else
		std::cout << "number not found\n";

	std::cout << "\n----test3----" << std::endl;
	std::vector<std::string> vec2;
	vec2.push_back("salut");
	vec2.push_back("hello");
	vec2.push_back("world");
	vec2.push_back("!");
	std::vector<std::string>::iterator i = std::find(vec2.begin(), vec2.end(), std::string("world"));
	if (i != vec2.end())
		std::cout << "'" << *i << "' found\n";
	else
		std::cout << "string not found\n";
}