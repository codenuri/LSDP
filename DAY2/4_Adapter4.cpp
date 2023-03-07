#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 포함을 사용한 어답터 : list 의 일부 기능만 stack이 사용

template<typename T>
class stack 
{
	std::list<T> c; // 클래스 어답터
//	std::list<T>* c;// 포인터 또는 참조로 해야 객체 어답터

public:
	void push(const T& a)	{ c.push_back(a); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

//	s.push_front(200); // error. 함수 없음.
}