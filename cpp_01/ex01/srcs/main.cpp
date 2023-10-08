#include "Zombie.hpp"
// #include <cstdlib> //system

# define HORDESIZE 7

int main() {
	Zombie *zombies = zombieHorde(HORDESIZE, "zombie");

	for (int i = 0; i < HORDESIZE; i++)
		zombies[i].announce();
	delete []zombies;
	// system("leaks ex01");
}
