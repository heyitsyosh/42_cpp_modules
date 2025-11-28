#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point &other): _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other) {
	if (this != &other) {
		const_cast<Fixed &>(_x) = other.getX();
		const_cast<Fixed &>(_y) = other.getY();
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}

Point Point::operator+(const Point &other) {
	Point result(_x.getRawBits() + other._x.getRawBits() \
				,_y.getRawBits() + other._y.getRawBits());
	return result;
}

Point Point::operator-(const Point &other) {
	Point result(_x.getRawBits() - other._x.getRawBits() \
				,_y.getRawBits() - other._y.getRawBits());
	return result;
}

std::ostream &operator<<(std::ostream &ostream, const Point &point) {
	return ostream << "(" << point.getX() << ", " << point.getY() << ")";
}
