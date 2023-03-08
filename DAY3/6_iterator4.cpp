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
		return slist_iterator<T>(head);  // new �ƴ�.. 
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

// �� ����� ������
// 1. GetEnumerator �� �ݺ��ڸ� new �� �����.
// 
// 2. MoveNext()�� GetObject()�� �����Լ��̴�. ������.

// 3. ��� �����̳ʰ� ������ ����� �ƴϴ�.
//    "�迭"�� MoveNext()�� �ƴ� ++p�� �̵��ؾ� �Ѵ�.