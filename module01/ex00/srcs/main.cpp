#include "Zombie.hpp"

int main() {
	randomChump("Brainstein");

	Zombie *z =newZombie("Rottenstein");
	z->announce();
	delete z;
}
