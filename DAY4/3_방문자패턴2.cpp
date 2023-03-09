#include <iostream>
#include <list>
#include <vector>

// 1. �湮���� �������̽�
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 2. �湮�ڴ� �ᱹ ����ϳ��� ���� ������ ������ Ŭ���� �Դϴ�.
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { e *= 2; }
};
//-----------------------------
// �湮�� ������ ����ϴ� ��� ���հ�ü�� accept�� �־�� �Ѵ�.
template<typename T> struct IAccept
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~IAccept() {}
};

// STL �� Ȯ���ؼ� �湮�� ���� ����
template<typename T> 
class MyList : public std::list<T>, public IAccept<T>
{
public:
	using std::list<T>::list; // list�� ��� �����ڸ� ����ش޶�

	void accept(IVisitor<T>* v) override
	{
		// �ٽ� : �ڽ��� ��� ��Ҹ� �湮�ڿ� �����ϸ� �˴ϴ�.
		for (auto& e : *this)
			v->visit(e);
	}
};
int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };
				// MyList(initializer_list) ����� ������ �ʿ�

	TwiceVisitor<int> tv; 
	s.accept(&tv);		   	

//	ShowVisitor<int> sv;   
//	s.accept(&sv);

}





