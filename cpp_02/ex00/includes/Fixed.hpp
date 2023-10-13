#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
private:
	int raw_value;
	static const int fractional_bits = 8;
};

#endif