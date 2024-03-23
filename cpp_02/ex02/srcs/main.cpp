#include <Fixed.hpp>

# define GREEN "\033[32m"
# define RESET "\033[0m"

void test1( void ) {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}

void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	Fixed a;
	Fixed  b( 2147.0f );
	Fixed  c( 80000.0f );
	Fixed  one( 1.0f ); 
	a = Fixed( 1234.4321f );

	/*a = 1234 b = 2147 c = 10 d = 10*/
	std::cout << "1234.4321 + 1234.4321 = "	<< (a+a) << std::endl;
	std::cout << "1234.4321 - 1234.4321 = "	<< (a-a) << std::endl;
	std::cout << "1234.4321 * 1234.4321 = "	<< (a*a) << std::endl;
	std::cout << "1234.4321 / 1234.4321 = "	<< (a/a) << std::endl;
	std::cout << "\n2147 + 2147 = "			<< (b+b) << std::endl;
	std::cout << "80000.0 / 1 = "		<< (c/one) << std::endl;
	std::cout << "1 / 1 = "					<< (one/one) << std::endl;
}

int	main( void ) {
	test1();
	std::endl(std::cout);
	test2();

	return 0;
}
