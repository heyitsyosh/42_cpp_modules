#ifndef POINT_HPP
#define POINT_HPP

class Fixed;
class Point {
public:
	Point();
	explicit Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();
	Fixed getX() const;
	Fixed getY() const;
private:
	const Fixed x;
	const Fixed y;
}

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif