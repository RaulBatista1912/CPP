#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
	const Animal* animals[100];

	for (int i = 0; i < 50; ++i)
		animals[i] = new Dog();

	for (int i = 50; i < 100; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < 100; i++) {
		std::cout << i + 1 << " : ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 100; ++i)
		delete animals[i];

	std::cout << "=======subject test=======" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

return 0;
}