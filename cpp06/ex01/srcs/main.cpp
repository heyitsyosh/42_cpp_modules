#include <iostream> //cout, endl
#include "Serializer.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

int main() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;

	Data data = {1, 0.01, 'a'};
	uintptr_t serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << &serialized << "\n"
		<< deserialized << "\n"
		<< "Int: " << deserialized->int_val << "\n"
		<< "Double: " << deserialized->double_val << "\n"
		<< "Char: " << deserialized->char_val << std::endl;
}
