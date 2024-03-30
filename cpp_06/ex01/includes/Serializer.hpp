#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> //uintptr_t

struct Data {
	int int_val;
	double double_val;
	char char_val;
};

class Serializer {
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();
};

#endif
