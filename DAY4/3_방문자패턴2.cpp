#include <iostream>
#include <list>
#include <vector>

// 1. 방문자의 인터페이스
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 2. 방문자는 결국 요소하나에 대한 연산을 정의한 클래스 입니다.
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) override { e *= 2; }
};
//-----------------------------
// 방문자 패턴을 사용하는 모든 복합객체는 accept가 있어야 한다.
template<typename T> struct IAccept
{
	virtual void accept(IVisitor<T>* v) = 0;
	virtual ~IAccept() {}
};

// STL 을 확장해서 방문자 패턴 적용
template<typename T> 
class MyList : public std::list<T>, public IAccept<T>
{
public:
	using std::list<T>::list; // list의 모든 생성자를 상속해달라

	void accept(IVisitor<T>* v) override
	{
		// 핵심 : 자신의 모든 요소를 방문자에 전달하면 됩니다.
		for (auto& e : *this)
			v->visit(e);
	}
};
int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };
				// MyList(initializer_list) 모양의 생성자 필요

	TwiceVisitor<int> tv; 
	s.accept(&tv);		   	

//	ShowVisitor<int> sv;   
//	s.accept(&sv);

}





