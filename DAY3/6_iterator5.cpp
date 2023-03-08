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
	inline slist_iterator operator++(int)
	{
		auto temp = *this;
		current = current->next;
		return temp;
	}



	inline T& operator*()
	{
		return current->data;
	}

	inline bool operator==(const slist_iterator& other)
	{
		return current == other.current;
	}

	inline bool operator!=(const slist_iterator& other)
	{
		return current != other.current;
	}
};








template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	// 모든 컨테이너 설계자는 자신의 반복자 이름을
	// iterator 라는 약속된 형태로 외부에 노출해야 한다.
	
	using iterator = slist_iterator<T>;

	inline iterator begin()
	{
		return iterator(head);   
	}

	inline iterator end()
	{
		return iterator(0);
	}
};



int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	slist<int>::iterator first = s.begin();
	slist<int>::iterator last = s.end();


	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}

}

// 위 방식의 장점
// 1. GetEnumerator 는 반복자를 new 로 만든다.
// ===> 이제 new를 사용하지 않고 있다... delete 필요 없다.
// 
// 2. MoveNext()와 GetObject()는 가상함수이다. 느리다.
// ===> 인라인 치환 된다. 아주 빠르다. 
// 
// 3. 모든 컨테이너가 동일한 방식이 아니다.
//    "배열"은 MoveNext()가 아닌 ++p로 이동해야 한다.
// ===> 배열과 동일하게 ++로 이동한다.