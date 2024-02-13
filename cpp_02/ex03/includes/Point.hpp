#ifndef POINT_HPP
#define POINT_HPP

#include <iostream> //ostream
#include "Fixed.hpp"

class Point {
public:
	Point();
	explicit Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
	Point operator+(Point const &other);
	Point operator-(Point const &other);
private:
	const Fixed x;
	const Fixed y;
};

std::ostream &operator<<(std::ostream& ostream, const Point& value);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
