#include "Fixed.hpp"
#include <cmath> //roundf

Fixed::Fixed(): raw_value(0) {}

Fixed::Fixed(const int int_value) {
	raw_value = int_value << fractional_bits;
}

Fixed::Fixed(const float float_value) {
	raw_value = roundf(float_value * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &other): raw_value(other.raw_value) {}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		raw_value = other.raw_value;
	return *this;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &other) {
	return ostream << other.toFloat();
}

Fixed::~Fixed() {}

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
	return raw_value >> fractional_bits;
}


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
	Fixed result;
	result.setRawBits(raw_value + other.raw_value);
	return result;
}

Fixed Fixed::operator-(Fixed const &other) {
	Fixed result;
	result.setRawBits(raw_value - other.raw_value);
	return result;
}

Fixed Fixed::operator*(Fixed const &other) {
	long long product = static_cast<long long>(raw_value) * other.raw_value;

	Fixed ret;
	ret.setRawBits(static_cast<int>(product >> fractional_bits));	
	return ret;
}

Fixed Fixed::operator/(Fixed const &other) {
	if (other.raw_value == 0)
		return Fixed(0);

	return Fixed(roundf(toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++() {
	raw_value++;
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
