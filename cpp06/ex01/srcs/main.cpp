#include <iostream> //cout, endl
#include "Serializer.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

int main() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;

	Data data = {1, 0.01, 'a'};
	uintptr_t serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Serialized address: " << &serialized << "\n"
		<< "Deserialized address: " <<  deserialized << "\n"
		<< "Int: " << data.int_val << ", " << deserialized->int_val << "\n"
		<< "Double: " << data.double_val << ", " << deserialized->double_val << "\n"
		<< "Char: " << data.char_val << ", " << deserialized->char_val << std::endl;
}
