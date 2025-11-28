#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack {
public:
	MutantStack(){};
	MutantStack(const MutantStack<T, Container> &other): _container(other._container) {};
	MutantStack &operator=(const MutantStack<T, Container> &other) {
		if (this != &other)
			_container = other._container;
		return (*this);
	};
	~MutantStack(){};
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	void push(const T &value) { _container.push_back(value); }
	void pop() { _container.pop_back(); }
	T &top() { return _container.back(); }
	const T &top() const { return _container.back(); }
	bool empty() const { return _container.empty(); }
	size_t size() const { return _container.size(); }

	iterator begin() { return _container.begin(); }
	iterator end() { return _container.end(); }
	const_iterator begin() const { return _container.begin(); }
	const_iterator end() const { return _container.end(); }
	reverse_iterator rbegin() { return _container.rbegin(); }
	reverse_iterator rend() { return _container.rend(); }
	const_reverse_iterator rbegin() const { return _container.rbegin(); }
	const_reverse_iterator rend() const { return _container.rend(); }
	Container &getContainer() { return _container; }
	const Container &getContainer() const { return _container; }
private:
	Container _container; 
};

#endif
