#include <iostream>
#include <list>
#include <vector>
#include <deque>


template<typename T, 
	template<typename, typename > class C = std::deque >
class stack
{
	C<T, std::allocator<T> > c;
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
//	stack<int, std::list<int> > s;
	stack<int, std::list > s;
	stack<int, std::vector > s;
}