#include "Zombie.hpp"
#include <iostream> //cerr, endl
#include <new> //bad_alloc
#include <cstdlib> //exit

Zombie *zombieHorde(int n, std::string name) {
	if (n <= 0)
		return NULL;

	Zombie *zombies = NULL;
	try {
		zombies = new Zombie[n];
	}
	catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	for (int i = 0; i < n; i++)
		zombies[i].setName(name);
	return (zombies);
}
