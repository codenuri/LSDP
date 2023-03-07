#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter

// STL �� �̹� list�� �ֽ��ϴ�.
// �׷���, ����ڰ� stack �䱸�մϴ�(�̹� ������,, ���ٰ� ����)

// list�� push_back() => push() �� �����ؼ� stack ó�� ���̰�


// ����� ����� �����
// => list�� ��� ����� stack �� ����ϰڴٴ� �ǹ�.
// => �� ���������� ���� ���� ������.
template<typename T>
class stack : public std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void pop()            { std::list<T>::pop_back(); }
	T&   top()            { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(200); // ����ڰ� �Ǽ��� ����ߴ�.
}