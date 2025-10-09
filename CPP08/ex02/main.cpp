#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);

std::cout << "---test with list---" << std::endl;
std::list<int> list;
list.push_back(5);
list.push_back(17);
std::cout << list.back() << std::endl;
list.pop_back();
std::cout << list.size() << std::endl;
list.push_back(3);
list.push_back(5);
list.push_back(737);
//[...]
list.push_back(0);
std::list<int>::iterator it2 = list.begin();
std::list<int>::iterator ite2 = list.end();
++it2;
--it2;
while (it2 != ite2)
{
std::cout << *it2 << std::endl;
++it2;
}

std::cout << "---test with non const iterator---" << std::endl;
MutantStack<int> intstack;
intstack.push(1);
intstack.push(2);
intstack.push(3);
intstack.push(4);
MutantStack<int>::iterator x = intstack.begin();
MutantStack<int>::iterator y = intstack.end();
while (x < y) {
	*x += 5;
	std::cout << *x << std::endl;
	x++;

}

std::cout << "---test with const iterator---" << std::endl;
MutantStack<int> cstack;
cstack.push(1);
cstack.push(2);
cstack.push(3);
MutantStack<int>::const_iterator p = cstack.begin();
MutantStack<int>::const_iterator q = cstack.end();
while (p < q) {
	//*p += 5;
	std::cout << *p << std::endl;
	p++;
}

std::cout << "---test with string const iterator---" << std::endl;
MutantStack<std::string> sstack;
sstack.push("hello");
sstack.push("world");
sstack.push("!");
sstack.push("I");
sstack.push("Like");
sstack.push("Turtles");
MutantStack<std::string>::const_iterator i = sstack.begin();
MutantStack<std::string>::const_iterator j = sstack.end();
//*it = ("test");
while (i != j) {
	std::cout << *i << std::endl;
	i++;
}
std::cout << "---reverse---" << std::endl;
i--;
std::cout << *i << std::endl;
i--;
std::cout << *i << std::endl;
i--;
std::cout << *i << std::endl;

return 0;
}