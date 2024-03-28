#include <Point.hpp>

static float crossProduct(Point a, Point b, Point c) {
	float ab_x = b.getX().toFloat() - a.getX().toFloat();
	float ab_y = b.getY().toFloat() - a.getY().toFloat();
	float ac_x = c.getX().toFloat() - a.getX().toFloat();
	float ac_y = c.getY().toFloat() - a.getY().toFloat();

	return ab_x * ac_y - ab_y * ac_x;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float pa = crossProduct(a, b, point);
	float pb = crossProduct(b, c, point);
	float pc = crossProduct(c, a, point);

	return (pa > 0 && pb > 0 && pc > 0) || (pa < 0 && pb < 0 && pc < 0);
}
