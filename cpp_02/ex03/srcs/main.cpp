#include "Fixed.hpp"
#include "Point.hpp"
#include <ios>

#define MAX (2147483648.0f/256)
#define MIN (1.0f/256)

void test1() {
	Point a(1, 1);
    Point b(3, -3);
    Point c(-5, 0);

}

void test2() {
    Point a(0,0);
    Point b(MAX,MAX);
    Point c(MAX,0);
    Point pt1(-1,-1);

    std::cout<<std::boolalpha;
    std::cout<< bsp(a,b,c,pt1) <<std::endl;
    std::cout<< (Fixed(MAX-1)-Fixed(MIN) == Fixed(MAX-1)) <<std::endl;
}

int main(){
	test1();
	std::endl(std::cout);
	test2();

	return 0;
}
