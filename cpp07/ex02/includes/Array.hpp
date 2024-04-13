#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream> //cout, endl

template <typename T>
class Array  {
public:
	Array(unsigned int n = 0): arr_size(n) { arr = new T[n]; }
	Array(const Array &other): arr_size(other.arr_size) {
		arr = new T[other.arr_size];
		for (unsigned int i; i < arr_size; i++)
			arr[i] = other.arr[i];
	}
	Array &operator=(const Array &other) {
		if (this != &other) {
			delete []arr;
			arr = new T[other.arr_size];
			arr_size = other.arr_size;
			for (unsigned int i = 0; i < arr_size; i++)
				arr[i] = other.arr[i];
		}
		return *this;
	}
	~Array() { delete []arr; }
	T &operator[](unsigned int i) {
		if (i >= arr_size)
			throw (std::exception());
		return (arr[i]);
	}
	const T &operator[](unsigned int i) const {
		if (i >= arr_size)
			throw (std::exception());
		return (arr[i]);
	}
	unsigned int size() const { return arr_size; }
	T *getArr() const { return arr; }
	void printArr() const { 
		for (unsigned int i = 0; i < arr_size; i++) {
			if (i != arr_size)
				std::cout << arr[i] << ' ';
			else
				std::cout << arr[i];
		}
		if (arr_size != 0)
			std::endl(std::cout);
	}
private:
	T *arr;
	unsigned int arr_size;
};

#endif
