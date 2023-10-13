#include "Fixed.hpp"
#include <iostream> //cout, endl, ostream
#include <cmath> //roundf
#include <climits> //INT_MAX, INT_MIN

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
	return getRawBits() >> fractional_bits;
}

// copy Fixed.cpp from ex01 later

bool Fixed::operator<(Fixed const &other) const {
	return (raw_value < other.raw_value);
}

bool Fixed::operator>(Fixed const &other) const {
	return (raw_value > other.raw_value);
}

bool Fixed::operator<=(Fixed const &other) const {
	return (raw_value <= other.raw_value);
}

bool Fixed::operator>=(Fixed const &other) const {
	return (raw_value >= other.raw_value);
}

bool Fixed::operator==(Fixed const &other) const {
	return (raw_value == other.raw_value);
}

bool Fixed::operator!=(Fixed const &other) const {
	return (raw_value != other.raw_value);
}

Fixed Fixed::operator+(Fixed const &other) {
	Fixed ret;

	ret.setRawBits(raw_value + other.raw_value);
	return ret;
}

Fixed Fixed::operator-(Fixed const &other) {
	Fixed ret;

	ret.setRawBits(raw_value - other.raw_value);
	return ret;
}

Fixed Fixed::operator*(Fixed const &other) {
	//implement
}

Fixed Fixed::operator/(Fixed const &other) {
	//implement
}

Fixed& Fixed::operator++() {
	++raw_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	raw_value++;
	return tmp;
}

Fixed& Fixed::operator--() {
	raw_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	raw_value--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return a;
	return b;
}
