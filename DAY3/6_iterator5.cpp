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

	// ��� �����̳� �����ڴ� �ڽ��� �ݺ��� �̸���
	// iterator ��� ��ӵ� ���·� �ܺο� �����ؾ� �Ѵ�.
	
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

// �� ����� ����
// 1. GetEnumerator �� �ݺ��ڸ� new �� �����.
// ===> ���� new�� ������� �ʰ� �ִ�... delete �ʿ� ����.
// 
// 2. MoveNext()�� GetObject()�� �����Լ��̴�. ������.
// ===> �ζ��� ġȯ �ȴ�. ���� ������. 
// 
// 3. ��� �����̳ʰ� ������ ����� �ƴϴ�.
//    "�迭"�� MoveNext()�� �ƴ� ++p�� �̵��ؾ� �Ѵ�.
// ===> �迭�� �����ϰ� ++�� �̵��Ѵ�.