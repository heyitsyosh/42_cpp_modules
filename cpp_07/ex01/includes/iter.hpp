#ifndef ITER_HPP
#define ITER_HPP

#include <stddef.h> //size_t

//could alter contents
template <typename T>
void iter(T *array, size_t length, void (*f)(T&)) {
	if (!array || !f)
		return;
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

//doesn't alter contents
template <typename T>
void iter(const T *array, size_t length, void (*f)(const T&)) {
	if (!array || !f)
		return;
	for (size_t i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif
