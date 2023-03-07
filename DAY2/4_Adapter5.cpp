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
#include <stack> // C++ ǥ���� stack �� ���� ���� ����Ǿ�
				// �ֽ��ϴ�. ���� stack adapter ��� �մϴ�.

int main()
{
	stack<int, std::list<int> > s;
	stack<int, std::vector<int> > s1;
	stack<int > s2;
	s.push(10);
}