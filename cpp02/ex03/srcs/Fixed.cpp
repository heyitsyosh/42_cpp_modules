#include <cmath> //roundf
#include "Fixed.hpp"

Fixed::Fixed(): _raw_value(0) {}

Fixed::Fixed(const int int_value) {
	_raw_value = int_value << _fractional_bits;
}

Fixed::Fixed(const float float_value) {
	_raw_value = roundf(float_value * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &other): _raw_value(other._raw_value) {}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		_raw_value = other._raw_value;
	return *this;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &other) {
	return ostream << other.toFloat();
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return _raw_value;
}

void Fixed::setRawBits(int const raw) {
	_raw_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_raw_value) / (1 << _fractional_bits);
}

int Fixed::toInt() const {
	return _raw_value >> _fractional_bits;
}

bool Fixed::operator<(Fixed const &other) const {
	return (_raw_value < other._raw_value);
}

bool Fixed::operator>(Fixed const &other) const {
	return (_raw_value > other._raw_value);
}

bool Fixed::operator<=(Fixed const &other) const {
	return (_raw_value <= other._raw_value);
}

bool Fixed::operator>=(Fixed const &other) const {
	return (_raw_value >= other._raw_value);
}

bool Fixed::operator==(Fixed const &other) const {
	return (_raw_value == other._raw_value);
}

bool Fixed::operator!=(Fixed const &other) const {
	return (_raw_value != other._raw_value);
}

Fixed Fixed::operator+(Fixed const &other) const {
	Fixed result;
	result.setRawBits(_raw_value + other._raw_value);
	return result;
}

Fixed Fixed::operator-(Fixed const &other) const {
	Fixed result;
	result.setRawBits(_raw_value - other._raw_value);
	return result;
}

Fixed Fixed::operator*(Fixed const &other) const {
	long product = static_cast<long>(_raw_value) * other._raw_value;

	Fixed ret;
	ret.setRawBits(static_cast<int>(product >> _fractional_bits));	
	return ret;
}

Fixed Fixed::operator/(Fixed const &other) const {
	if (other._raw_value == 0)
		return Fixed(0);

	return Fixed(roundf(toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++() {
	_raw_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	_raw_value++;
	return tmp;
}

Fixed& Fixed::operator--() {
	_raw_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	_raw_value--;
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
