#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	std::cout << "\n=============\n\n";

	const	WrongAnimal* wrongA = new WrongAnimal();
	const	WrongAnimal* wrongCat = new WrongCat();


	wrongA->makeSound();
	wrongCat->makeSound();

	delete wrongA;
	delete wrongCat;

	std::cout << "\n=============\n\n";

	WrongCat originalWrongCat;
	originalWrongCat.makeSound();

	return 0;
}