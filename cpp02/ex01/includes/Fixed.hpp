#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> //ostream

class Fixed {
public:
	Fixed();
	explicit Fixed(const int);
	explicit Fixed(const float);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
private:
	int raw_value;
	static const int fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &value);

#endif
