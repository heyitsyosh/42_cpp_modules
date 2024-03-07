#ifndef ITER_HPP
#define ITER_HPP

#include <stddef.h>

//so what i don't get enough about type T. should i do it with a const T &?
template <typename T>
void iter(T *array, size_t length, void (*f)(T)) {
	for (size_t i = 0; i < length; i++)  {
		f(array[i]);
	}
}

#endif
