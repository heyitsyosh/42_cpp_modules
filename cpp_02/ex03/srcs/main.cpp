#include "Fixed.hpp"
#include "Point.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"

#define MAX (2147483648.0f/256)
#define MIN (1.0f/256)

//p in triangle
void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3);
    Point p(2, 1);

    std::cout<<std::boolalpha;
    std::cout<< bsp(a,b,c,p) <<std::endl;
}

//p on edge
void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	Point a(1, 2);
    Point b(4, 5);
    Point c(6, 3);
    Point p(5, 4);

    std::cout<<std::boolalpha;
    std::cout<< bsp(a,b,c,p) <<std::endl;
}

void test3() {
    std::cout << GREEN "[Test 3]" RESET << std::endl;
    Point a(0,0);
    Point b(MAX,MAX);
    Point c(MAX,0);
    Point p(-1,-1);

    std::cout<<std::boolalpha;
    std::cout<< bsp(a,b,c,p) <<std::endl;
    std::cout<< (Fixed(MAX-1)-Fixed(MIN) == Fixed(MAX-1)) <<std::endl;
}

int main(){
	test1();
	test2();
	test3();

	return 0;
}
