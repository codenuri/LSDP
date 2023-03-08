#include <iostream>


template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// ��� ������(�ݺ���)�� ������ �����ؾ� �Ѵ�.
template<typename T>
struct IEnumerator
{
	virtual bool MoveNext() = 0;
	virtual T& GetObject() = 0;
	virtual ~IEnumerator() {}
};

// ��� �����̳ʿ����� �ݺ��ڸ� ������ �־�� �Ѵ�.
template<typename T>
struct IEnumerable
{
	virtual IEnumerator<T>* GetEnumerator() = 0;
	virtual ~IEnumerable() {}
};
//-----------------------------------------

// slist �� �ݺ���

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








// ��� �����̳ʴ� �ݺ��ڸ� ������ �־�� �Ѵ�.
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

// �� ����� ������
// 1. GetEnumerator �� �ݺ��ڸ� new �� �����.
// 
// 2. MoveNext()�� GetObject()�� �����Լ��̴�. ������.

// 3. ��� �����̳ʰ� ������ ����� �ƴϴ�.
//    "�迭"�� MoveNext()�� �ƴ� ++p�� �̵��ؾ� �Ѵ�.