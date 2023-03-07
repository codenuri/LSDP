#include <iostream>
#include <list>
#include <vector>
#include <deque>


template<typename T, typename C = std::deque<T> >
class stack
{
	C c; 
public:
	void push(const T& a) { c.push_back(a); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};
#include <stack> // C++ 표준의 stack 이 위와 같이 설계되어
				// 있습니다. 흔히 stack adapter 라고 합니다.

int main()
{
	stack<int, std::list<int> > s;
	stack<int, std::vector<int> > s1;
	stack<int > s2;
	s.push(10);
}