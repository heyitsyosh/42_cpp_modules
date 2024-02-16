#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
	if (this != &other) {
		const_cast<Fixed &>(x) = other.getX();
		const_cast<Fixed &>(y) = other.getY();
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
	return x;
}

Fixed Point::getY() const {
	return y;
}

Point Point::operator+(const Point &other) {
	Point result(x.getRawBits() + other.x.getRawBits() \
				,y.getRawBits() + other.y.getRawBits());
	return result;
}

Point Point::operator-(const Point &other) {
	Point result(x.getRawBits() - other.x.getRawBits() \
				,y.getRawBits() - other.y.getRawBits());
	return result;
}

std::ostream &operator<<(std::ostream &ostream, const Point &point) {
	return ostream << "(" << point.getX() << ", " << point.getY() << ")";
}
