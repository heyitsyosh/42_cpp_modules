#include "Fixed.hpp"
#include <iostream> //cout, endl
#include <cmath> //roundf
#include <climits> //INT_MAX, INT_MIN

Fixed::Fixed() 
: raw_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value) {
	std::cout << "Parameterized constructor called" << std::endl;
	raw_value = int_value << fractional_bits;
	// idk idk idk what to do
	// if (raw_value != int_value >> fractional_bits) {
	// 	if (int_value > 0)
	// 		raw_value = INT_MAX;
	// 	else
	// 		raw_value = INT_MIN;
	// }
}

Fixed::Fixed(const float float_value) {
	std::cout << "Parameterized constructor called" << std::endl;
	raw_value = roundf(float_value * (1 << fractional_bits));
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

std::ostream &operator<<(std::ostream &ostream, const Fixed &value) {
	ostream << value.toFloat();
	return (ostream);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return raw_value;
}

void Fixed::setRawBits(int const raw) {
	raw_value = raw;
}

float Fixed::toFloat() const {
	// float f;
}

int Fixed::toInt() const {
	// int i;
}
