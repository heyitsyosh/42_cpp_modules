#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack {
public:
	MutantStack(){};
	MutantStack(const MutantStack<T, Container> &other): container(other.container) {};
	MutantStack &operator=(const MutantStack<T, Container> &other) {
		if (this != &other)
			container = other.container;
		return (*this);
	};
	~MutantStack(){};
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	void push(const T &value) { container.push_back(value); }
	void pop() { container.pop_back(); }
	T &top() { return container.back(); }
	const T &top() const { return container.back(); }
	bool empty() const { return container.empty(); }
	size_t size() const { return container.size(); }

	iterator begin() { return container.begin(); }
	iterator end() { return container.end(); }
	const_iterator begin() const { return container.begin(); }
	const_iterator end() const { return container.end(); }
	reverse_iterator rbegin() { return container.rbegin(); }
	reverse_iterator rend() { return container.rend(); }
	const_reverse_iterator rbegin() const { return container.rbegin(); }
	const_reverse_iterator rend() const { return container.rend(); }
	Container &getContainer() { return container; }
	const Container &getContainer() const { return container; }
private:
	Container container; 
};

#endif
