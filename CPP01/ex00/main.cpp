#include "Zombie.hpp"
#include <unistd.h>

int main() {
	Zombie* z = newZombie("HeapZombie");
	z->announce();
	randomChump("StackZombie");
	delete z;
	return (0);
}