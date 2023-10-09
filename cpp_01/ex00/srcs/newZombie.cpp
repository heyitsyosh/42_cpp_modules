#include "Zombie.hpp"
#include <iostream> //cerr, endl
#include <new> //bad_alloc
#include <cstdlib> //exit

Zombie *newZombie(std::string name) {
	Zombie *zombie;
	try {
		zombie = new Zombie(name);
	}
	catch (const std::bad_alloc &e){
		std::cerr << e.what() << std::endl;
		std::exit(1);
	}
	return (zombie);
}
