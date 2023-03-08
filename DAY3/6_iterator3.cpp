#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 모든 열거자(반복자)는 사용법이 동일해야 한다.
template<typename T>
struct IEnumerator
{
	virtual bool MoveNext() = 0;
	virtual T& GetObject() = 0;
	virtual ~IEnumerator() {}
};

// 모든 컨테이너에서는 반복자를 꺼낼수 있어야 한다.
template<typename T>
struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};
//-----------------------------------------

// slist 의 반복자

template<typename T>
class slist_enumerator : public IEnumerator<T>
{
	Node<T>* current = 0;
public:
	slist_enumerator(Node<T>* p = 0) : current(p) {}

	bool MoveNext() override
	{
		current = current->next;

		return current != 0;
	}
	T& GetObject() override
	{
		return current->data;
	}

};








// 모든 컨테이너는 반복자를 꺼낼수 있어야 한다.
template<typename T> struct slist : public IEnumerable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	
	IEnumerator<T>* GetEnumerator() override 
	{
		return new slist_enumerator<T>(head);
	}
};






int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	IEnumerator<int>* p = s.GetEnumerator();

	do
	{
		std::cout << p->GetObject() << std::endl;

	} while (p->MoveNext());
}

// 위 방식의 문제점
// 1. GetEnumerator 는 반복자를 new 로 만든다.
// 
// 2. MoveNext()와 GetObject()는 가상함수이다. 느리다.

// 3. 모든 컨테이너가 동일한 방식이 아니다.
//    "배열"은 MoveNext()가 아닌 ++p로 이동해야 한다.