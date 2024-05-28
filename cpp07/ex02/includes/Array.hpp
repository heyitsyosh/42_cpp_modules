#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream> //cout, endl, (cerr)

template <typename T>
class Array  {
public:
	Array(unsigned int n = 0): _arr_size(n) { _arr = new T[n]; }
	Array(const Array &other): _arr_size(other._arr_size) {
		_arr = new T[other._arr_size];
		for (unsigned int i = 0; i < _arr_size; i++)
			_arr[i] = other._arr[i];
	}
	Array &operator=(const Array &other) {
		if (this != &other) {
			delete []_arr;
			_arr = new T[other._arr_size];
			_arr_size = other._arr_size;
			for (unsigned int i = 0; i < _arr_size; i++)
				_arr[i] = other._arr[i];
		}
		return *this;
	}
	~Array() { delete []_arr; }
	T &operator[](unsigned int i) {
		if (i >= _arr_size)
			throw (std::exception());
		return (_arr[i]);
	}
	const T &operator[](unsigned int i) const {
		if (i >= _arr_size)
			throw (std::exception());
		return (_arr[i]);
	}
	unsigned int size() const { return _arr_size; }
	T *getArr() const { return _arr; }
	void printArr() const { 
		for (unsigned int i = 0; i < _arr_size; i++) {
			if (i != _arr_size)
				std::cout << _arr[i] << ' ';
			else
				std::cout << _arr[i];
		}
		if (_arr_size != 0)
			std::endl(std::cout);
	}
private:
	T *_arr;
	unsigned int _arr_size;
};

#endif
