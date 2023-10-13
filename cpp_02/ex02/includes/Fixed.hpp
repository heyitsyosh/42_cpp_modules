#ifndef FIXED_HP
# define FIXED_HPP

#include <string>

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
	bool operator<(Fixed const &rhs) const;
	bool operator>(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	Fixed operator+(Fixed const &rhs);
	Fixed operator-(Fixed const &rhs);
	Fixed operator*(Fixed const &rhs);
	Fixed operator/(Fixed const &rhs);
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
private:
	int raw_value;
	static const int fractional_bits = 8;
};

#endif