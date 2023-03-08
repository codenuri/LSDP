#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};




template<typename T>
class slist_iterator 
{
	Node<T>* current = 0;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;

		return *this;
	}


	inline T& operator*()
	{
		return current->data;
	}

};








template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	inline slist_iterator<T> begin()
	{
		return slist_iterator<T>(head);  // new 아님.. 
	}
};

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	
	slist_iterator<int> p = s.begin();

	std::cout << *p << std::endl; // 40

	++p;
	std::cout << *p << std::endl; // 30




}

// 위 방식의 문제점
// 1. GetEnumerator 는 반복자를 new 로 만든다.
// 
// 2. MoveNext()와 GetObject()는 가상함수이다. 느리다.

// 3. 모든 컨테이너가 동일한 방식이 아니다.
//    "배열"은 MoveNext()가 아닌 ++p로 이동해야 한다.