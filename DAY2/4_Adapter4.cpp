#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ������ ����� ����� : list �� �Ϻ� ��ɸ� stack�� ���

template<typename T>
class stack 
{
	std::list<T> c; // Ŭ���� �����
//	std::list<T>* c;// ������ �Ǵ� ������ �ؾ� ��ü �����

public:
	void push(const T& a)	{ c.push_back(a); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

//	s.push_front(200); // error. �Լ� ����.
}