#include <iostream> //cout, endl
#include <list>
#include "MutantStack.hpp"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// Test taken from subject documentation
void test1() {
	std::cout << GREEN "[Test 1] --- [default container ver.]" RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack.getContainer());
}

void test2() {
	std::cout << GREEN "[Test 2] --- [std::list ver.]" RESET << std::endl;
	// Container type for mstack is specified as std::list
	MutantStack<int, std::list<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int, std::list<int> >::iterator it = mstack.begin();
	MutantStack<int, std::list<int> >::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, std::list<int> > s(mstack.getContainer());
}

void test3() {
	std::cout << GREEN "[Test 3] --- [miscellaneous ver.]" RESET << std::endl;
	MutantStack<int> mstack;
	for (int i = 0 ; i < 5; i++)
		mstack.push(i + 1);

	// Testing copy constructor
	MutantStack<int> copy_stack(mstack);
	std::cout << "Copied stack size: " << copy_stack.size() << std::endl;

	// Testing copy assignment operator
	MutantStack<int> assign_stack;
	assign_stack = mstack;
	std::cout << "Assigned stack size: " << assign_stack.size() << std::endl;

	// Print elements
	std::cout << "Elements: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Print elements in reverse
	std::cout << "Elements in reverse: ";
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	// Testing top, size, pop
	std::cout << "Top: " << mstack.top() << ", size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "(Using pop on stack...)" << std::endl;
	std::cout << "Top: " << mstack.top() << ", size: " << mstack.size() << std::endl;

	// Testing empty
	std::cout << "(Using pop till empty...)" << std::endl;
	while (!mstack.empty())
		mstack.pop();
	std::cout << "Stack empty after pops: " << (mstack.empty() ? "Yes" : "No") << std::endl;
}

void test4() {
	std::cout << GREEN "[Test 4] --- [const ver.]" RESET << std::endl;
	MutantStack<int> mstack;
	for (int i = 0; i < 5; i++)
		mstack.push(i + 1);

	const MutantStack<int>& const_mtack = mstack;
	std::cout << "Const MutantStack elements: ";
	for (MutantStack<int>::const_iterator it = const_mtack.begin(); it != const_mtack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {
	test1();
	test2();
	test3();
	test4();

	return 0;
}
