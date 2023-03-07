#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter

// STL 에 이미 list가 있습니다.
// 그런데, 사용자가 stack 요구합니다(이미 있지만,, 없다고 가정)

// list의 push_back() => push() 로 변경해서 stack 처럼 보이게


// 상속을 사용한 어답터
// => list의 모든 기능을 stack 도 사용하겠다는 의미.
// => 이 예제에서는 좋지 않은 디자인.
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

	s.push_front(200); // 사용자가 실수로 사용했다.
}