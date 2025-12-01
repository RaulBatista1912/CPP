#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	vec.push_back(12);
	vec.push_back(9);
	vec.push_back(42);
	vec.push_back(76);
	
	std::cout << "----test1----" << std::endl;
	std::vector<int>::iterator it = easyfind(vec, 42);
	if (it != vec.end())
		std::cout << *it << " found\n";
	else
		std::cout << "number not found\n";

	std::cout << "\n----test2----" << std::endl;
	std::vector<int>::iterator it2 = easyfind(vec, 2);
	if (it2 != vec.end())
		std::cout << *it2 << " found\n";
	else
		std::cout << "number not found\n";

	std::cout << "\n----test3----" << std::endl;
	std::list<int> list;
	list.push_back(1);
	list.push_back(5);
	list.push_back(7);
	list.push_back(52);
	std::list<int>::iterator it3 = easyfind(list, 7);
	if (it3 != list.end())
		std::cout << *it3 << " found\n";
	else
		std::cout << "number not found\n";

}