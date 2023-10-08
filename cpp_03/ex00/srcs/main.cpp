#include "ClapTrap.hpp"
#include <climits>  // UINT_MAX

int main() {
	ClapTrap claptrap("CL4P-TP");
	std::string player = "Tiny Tina";

	claptrap.attack(player);
	claptrap.beRepaired(UINT_MAX);
	claptrap.beRepaired(1);
	claptrap.takeDamage(UINT_MAX - 5);
	for (int i = 0; i < 8; i++)
		claptrap.attack("[filler to use up energy points]");
	claptrap.beRepaired(1);
	claptrap.attack(player);
}
