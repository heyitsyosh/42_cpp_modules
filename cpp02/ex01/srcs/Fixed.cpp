#include <cmath> //roundf
#include "Fixed.hpp"

Fixed::Fixed() 
: raw_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value) {
	std::cout << "Int constructor called" << std::endl;
	raw_value = int_value << fractional_bits;
}

Fixed::Fixed(const float float_value) {
	std::cout << "Float constructor called" << std::endl;
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

std::ostream &operator<<(std::ostream &ostream, const Fixed &other) {
	return ostream << other.toFloat();
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
	return static_cast<float>(raw_value) / (1 << fractional_bits);
}

int Fixed::toInt() const {
	return raw_value >> fractional_bits;
}
