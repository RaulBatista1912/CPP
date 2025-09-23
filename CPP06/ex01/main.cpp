#include "Serializer.hpp"
#include <iostream>

int	main() {
	Data a;
	a.age = 42;
	a.nom = "Pierre";
	a.darkestSecret ="aime les pates au ketchup";
	a.taille = 1.82;

	uintptr_t raw = Serializer::serialize(&a);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << ptr->age << std::endl;
	std::cout << ptr->nom << std::endl;
	std::cout << ptr->darkestSecret << std::endl;
	std::cout << ptr->taille << std::endl;


	return (0);
}