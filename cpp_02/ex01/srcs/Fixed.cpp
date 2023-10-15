#include "Fixed.hpp"
#include <cmath> //roundf
#include <climits> //INT_MAX, INT_MIN

Fixed::Fixed() 
: raw_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value) {
	std::cout << "Parameterized constructor called" << std::endl;
	raw_value = int_value << fractional_bits; //multiplying by 256
	if (raw_value >> fractional_bits != int_value)
		raw_value = (int_value > 0) ? INT_MAX : INT_MIN;
}

Fixed::Fixed(const float float_value) {
	std::cout << "Parameterized constructor called" << std::endl;
	raw_value = roundf(float_value * (1 << fractional_bits)); //same meaning, but cannot apply bitshift to float
	//handle overflow?
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

//-0.1
//1000 0000 0000 0001
//1111 1111 1000 0000
//bit shifting negative is arithmetic (fills left with 1)
int Fixed::toInt() const {
	if (raw_value > 0)
		return raw_value >> fractional_bits;
	return (raw_value + (1 << (fractional_bits - 1))) >> fractional_bits;
}
