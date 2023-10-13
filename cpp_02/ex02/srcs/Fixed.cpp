#include "Fixed.hpp"
#include <iostream> //cout, endl
#include <cmath> //roundf
#include <climits> //INT_MAX, INT_MIN

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
