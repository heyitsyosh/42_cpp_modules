#include "Fixed.hpp"
#include <iostream> //cout, endl, ostream
#include <cmath> //roundf
#include <climits> //INT_MAX, INT_MIN
#include <stdio.h>

Fixed::Fixed() 
: raw_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value) {
	std::cout << "Parameterized constructor called" << std::endl;
	raw_value = int_value << fractional_bits;
	if (int_value != raw_value >> fractional_bits) {
		if (int_value > 0)
			raw_value = INT_MAX;
		else
			raw_value = INT_MIN;
	}
}

Fixed::Fixed(const float float_value) {
	std::cout << "Parameterized constructor called" << std::endl;
	(void)float_value;
	//whatttttttttttttttttt idk idk idk
	// int base = (float_value > 0) ? static_cast<int>(floor(float_value)) : static_cast<int>(ceil(float_value));
	// float fraction = base - float_value;
	// raw_value = base << fractional_bits;
	// // raw_value |= (int)fraction;
	// printf("raw_value: %d, base: %d, fraction: %f\n", raw_value, base, fraction);
}

Fixed::Fixed(const Fixed &other) 
: raw_value(other.raw_value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		raw_value = other.raw_value;
	return *this;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &other) {
	return ostream << other.toFloat();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return raw_value;
}

void Fixed::setRawBits(int const raw) {
	raw_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(raw_value) / (1 << fractional_bits);
}

int Fixed::toInt() const {
	return getRawBits() >> fractional_bits;
}
