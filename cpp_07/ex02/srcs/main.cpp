#include <Array.hpp>

# define GREEN "\033[32m"
# define RESET "\033[0m"

template class Array<int>;

void set_int_arr(int n, Array<int> &a) {
	for (size_t i = 0; i < a.size(); i++)
		a[i] = n;
}

// Testing default constructor
void test1() {
	std::cout << GREEN "[Test 1]" RESET << std::endl;
	Array<int> arr_int;

	arr_int.printArr();
	std::cout << "Arr_size: " << arr_int.size() << std::endl;
}

// Testing = operator
void test2() {
	std::cout << GREEN "[Test 2]" RESET << std::endl;
	Array<int> arr_int(5);
	Array<int> arr_int2(5);

	set_int_arr(1, arr_int);
	set_int_arr(2, arr_int2);
	
	arr_int.printArr();
	arr_int = arr_int2;
	arr_int.printArr();
}

// Testing copy constructor
void test3() {
	std::cout << GREEN "[Test 3]" RESET << std::endl;
	Array<int> arr_int(5);
	Array<int> arr_int2(arr_int);
	
	std::cout << arr_int.getArr() << "\n" << arr_int2.getArr() << std::endl;
}

// Testing [] operator out-of-range exceptions
void test4() {
	std::cout << GREEN "[Test 4]" RESET << std::endl;
	Array<int> arr_int(5);

	set_int_arr(1, arr_int);
	try {
		std::cout << arr_int[4] << std::endl;
		std::cout << arr_int[5] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	test1();
	test2();
	test3();
	test4();

	return 0;
}

/*
#include <cstdlib> //rand, srand, NULL
#include <exception>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}
*/
