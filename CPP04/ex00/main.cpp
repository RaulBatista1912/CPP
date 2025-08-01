#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	const	WrongAnimal* wrong = new WrongAnimal();
	const	WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongCat is a " << wrongCat->getType() << std::endl;

	wrong->makeSound();
	wrongCat->makeSound();

	delete wrong;
	delete wrongCat;

	WrongCat originalWrongCat;
	WrongCat copiedWrongCat(originalWrongCat);
	copiedWrongCat.makeSound();

	return 0;
}